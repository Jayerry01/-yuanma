// meteor_trace.js — Meteor.exe (2002, no ASLR, base 0x400000) 事件级采集
// Frida 17 API：NativePointer.read* 方法（Memory.read* 已移除）。
// 32 位 thiscall：ECX=this，栈参从 args[0] 起。
'use strict';

let t0 = Date.now();
function ts() { return ((Date.now() - t0) / 1000).toFixed(3); }

function safe(fn) { try { return fn(); } catch (e) { return 'ERR:' + e.message; } }

// 方向缓冲：this+0x2E8 = {begin, end, capacity}
function dirbuf(esi) {
    return safe(function () {
        const begin = ptr(esi).add(0x2E8).readPointer();
        const end = ptr(esi).add(0x2EC).readPointer();
        const len = end.sub(begin).toInt32();
        if (len <= 0 || len > 4096) return '<len=' + len + '>';
        const u8 = new Uint8Array(begin.readByteArray(Math.min(len, 64)));
        let s = '';
        for (let i = 0; i < u8.length; i++) {
            const c = u8[i];
            s += (c === 0x66) ? 'f' : (c === 0x62) ? 'b' : (c === 0x6c) ? 'l' : (c === 0x72) ? 'r' : ('\\x' + c.toString(16));
        }
        return '"' + s + '"';
    });
}

function hook(addr, name, fmt) {
    try {
        Interceptor.attach(ptr(addr), {
            onEnter: function (args) {
                const c = this.context;
                const line = fmt.call(this, {
                    args: args, ecx: c.ecx, edx: c.edx, eax: c.eax,
                    ebx: c.ebx, esi: c.esi, edi: c.edi,
                    ret: this.returnAddress
                });
                send('[' + ts() + '] ' + name + ' | ' + line);
            }
        });
        send('[' + ts() + '] HOOKED ' + name + ' @ ' + addr);
    } catch (e) {
        send('[' + ts() + '] HOOK-FAIL ' + name + ' @ ' + addr + ' : ' + e);
    }
}

// ---- 1. 状态 setter 咽喉（所有 [+0xDC] 写入必经；1 参栈调用）----
hook(0x4D0500, 'SetState', function (c) {
    return 'state=' + c.args[0].toInt32() + ' caller=' + c.ret;
});

// ---- 2. 状态复位 ----
hook(0x4CB0A7, 'StateReset', function (c) {
    return 'reset val=' + c.edi;
});

// ---- 3. 键事件入口（keyCode, pressed）----
hook(0x4CB820, 'KeyEvent', function (c) {
    return 'key=0x' + (c.args[0].toInt32() >>> 0).toString(16) + ' pressed=' + c.args[1].toInt32();
});

// ---- 4. 方向字符写（栈参 → BL → [ecx]）----
hook(0x4CBD41, 'DirChar', function (c) {
    const ch = c.ebx & 0xFF;
    const chName = (ch === 0x66) ? 'f' : (ch === 0x62) ? 'b' : (ch === 0x6c) ? 'l' : (ch === 0x72) ? 'r' : String.fromCharCode(ch);
    return 'dir="' + chName + '" dest=0x' + c.ecx.toString(16);
});

// ---- 5. 跳跃/攻击时钟武装 ----
hook(0x4CF510, 'ClockArm', function (c) {
    return 'clock=0x' + c.eax.toString(16);
});

// ---- 6. 持跳判别两分支 ----
hook(0x4CF573, 'JumpDisc', function (c) { return 'SMALL (elapsed<threshold → 282)'; });
hook(0x4CF57F, 'JumpDisc', function (c) { return 'BIG (elapsed>=threshold → 375)'; });

// ---- 7. cmd 0x1D 处理器入口 ----
hook(0x4BC710, 'CmdAttack', function (c) { return 'enter'; });

// ---- 8. 攻击执行器入口 ----
hook(0x4CFF40, 'Executor', function (c) { return 'enter'; });

// ---- 9. 跳跃派发器（读 [+0xDC] 三态）----
hook(0x004CF5B0, 'JumpDispatch', function (c) {
    const st = safe(function () { return ptr(c.ecx).add(0xDC).readS32(); });
    return 'jump-dispatch state=' + st;
});

// ---- 10. 十槽扇出（11 个调用点；EAX = this 的 vfptr 0x5AA660）----
const FANOUT = [
    [0x4CC3F3, 0xE8], [0x4CC439, 0xE8], [0x4CC4DB, 0xCC], [0x4CC4C2, 0xD0],
    [0x4CC4F1, 0xD4], [0x4CC51D, 0xD8], [0x4CC533, 0xDC], [0x4CC46B, 0xE4],
    [0x4CC507, 0xEC], [0x4CC549, 0xF0]
];
const SLOT_FN = {
    '0x4ccc70': 'slot51 walljump-pose(52B)', '0x4cc650': 'slot52 (218B)',
    '0x4d1e60': 'slot53 (20B)', '0x4cc730': 'slot54 (93B)',
    '0x4ce3c0': 'slot55 (16B)', '0x4cfd20': 'slot56 EquipWeapon(68B)',
    '0x4cfd70': 'slot57 (452B)', '0x4cff40': 'slot58 ATTACK-EXECUTOR(674B)',
    '0x4d0350': 'slot59 (150B)', '0x4ce2a0': 'slot60 (47B)'
};
FANOUT.forEach(function (p) {
    hook(p[0], 'FanOut', function (c) {
        const vfptr = c.eax;
        const tgt = safe(function () { return vfptr.add(p[1]).readPointer(); });
        const dir = safe(function () { return dirbuf(c.esi); });
        const tgtName = safe(function () { return SLOT_FN[tgt.toString()] || ('0x' + tgt.toString(16)); });
        return 'slot' + (p[1] / 4) + ' target=' + tgtName + ' dirbuf=' + dir;
    });
});

// ---- 11. 电平采样器（250ms：GameApp→pc→状态/朝向/速度链）----
setInterval(function () {
    const line = safe(function () {
        const gameApp = ptr('0x6659B8').readPointer();
        if (gameApp.isNull()) return null;
        const pc = gameApp.add(0x262C).readPointer();
        if (pc.isNull()) return null;
        const state = pc.add(0xDC).readS32();
        const sub = pc.add(0xE0).readS32();
        const grounded = pc.add(0x60).readS32();
        const wall = pc.add(0x64).readS32();
        const vx = pc.add(0x390).readFloat().toFixed(1);
        const vy = pc.add(0x394).readFloat().toFixed(1);
        const vz = pc.add(0x398).readFloat().toFixed(1);
        let pose = '?';
        const tn = pc.add(0x10).readPointer();
        if (!tn.isNull()) {
            const actor = tn.sub(0x65C);
            pose = String(actor.add(0x5E0).readS32());
        }
        const dir = safe(function () {
            const out = [];
            [['pc', pc], ['pc+8', pc.add(8)]].forEach(function (p) {
                const s = dirbuf(p[1]);
                if (s && s.indexOf('\\x') === -1 && s.indexOf('<len=') === -1) out.push(p[0] + '=' + s);
            });
            return out.join(' ') || '?';
        });
        return 'LEVEL state=' + state + ' sub=' + sub + ' grounded=' + grounded +
               ' wall=' + wall + ' vel=(' + vx + ',' + vy + ',' + vz + ') pose=' + pose + ' dirbuf=' + dir;
    });
    if (line) send('[' + ts() + '] LEVEL | ' + line);
}, 250);

send('[' + ts() + '] SCRIPT LOADED — hooks armed, sampler 250ms');
