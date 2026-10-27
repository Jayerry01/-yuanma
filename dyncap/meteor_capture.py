#!/usr/bin/env python3
"""meteor_capture.py — Meteor.exe 事件级采集驱动（Frida 附加/拉起）。

用法：
  python meteor_capture.py spawn            # 由 Frida 拉起游戏并从头采集
  python meteor_capture.py attach           # 附加到已在运行的 Meteor.exe
  python meteor_capture.py attach <pid>     # 多开时按 PID

输出：capture_log.jsonl（与脚本同目录），每行一个事件。
Ctrl+C 停止；停止时会打印事件计数。
"""
import frida
import sys
import time
import json
from datetime import datetime

GAME = r"C:\Program Files (x86)\Meteor\Meteor.exe"
SCRIPT_PATH = r"D:\MeteorProjects\_private\dyncap\meteor_trace.js"
OUT_PATH = r"D:\MeteorProjects\_private\dyncap\capture_log.jsonl"

count = 0
out = open(OUT_PATH, "a", encoding="utf-8")


def on_message(message, _data):
    global count
    if message["type"] == "send":
        count += 1
        out.write(json.dumps({"t": datetime.now().isoformat(timespec="milliseconds"),
                              "m": message["payload"]}, ensure_ascii=False) + "\n")
        out.flush()
        if count % 200 == 0:
            print(f"  …{count} 事件")
    elif message["type"] == "error":
        print("  [脚本错误]", message.get("description", message)[:200])


def main():
    mode = sys.argv[1] if len(sys.argv) > 1 else "attach"
    js = open(SCRIPT_PATH, encoding="utf-8").read()

    if mode == "spawn":
        pid = frida.spawn(GAME)
        session = frida.attach(pid)
        print(f"已拉起 Meteor.exe (pid {pid})，注入采集脚本…")
        frida.resume(pid)
    else:
        target = sys.argv[2] if len(sys.argv) > 2 else "Meteor.exe"
        try:
            pid = int(target)
        except ValueError:
            pid = target
        session = frida.attach(pid)
        print(f"已附加到 Meteor.exe (pid {session._impl.pid if hasattr(session._impl,'pid') else target})")

    script = session.create_script(js)
    script.on("message", on_message)
    script.load()
    duration = int(sys.argv[2]) if mode == "attach" and len(sys.argv) > 2 and sys.argv[2].isdigit() else 900
    print(f"采集进行中（模式={mode}, 时长={duration}s）——攻击、搓招、攀爬、蹬墙、换武器。")
    try:
        time.sleep(duration)
    except KeyboardInterrupt:
        pass
    print(f"\n共 {count} 事件 → {OUT_PATH}")
    session.detach()


if __name__ == "__main__":
    main()
