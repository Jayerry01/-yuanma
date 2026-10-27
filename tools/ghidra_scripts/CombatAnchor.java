import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.*;
import java.io.*;
import java.util.*;

public class CombatAnchor extends GhidraScript {
    public void run() throws Exception {
        Program program = currentProgram;
        Listing listing = program.getListing();
        ReferenceManager refMgr = program.getReferenceManager();
        FunctionManager fm = program.getFunctionManager();

        Set<String> en = new HashSet<>(Arrays.asList(new String[]{
            "attack","action","move","hit","animation","weapon","block","frame",
            "critical","guard","kick","damage","sword","combo","defend","parry",
            "stun","knock","blood","punch","hammer","spear","staff","rush","dodge",
            "counter","hitstun","knockback"}));
        String[] cn = {"刀","剑","锤","棍","枪","拳","脚","招","攻击","防御","连招",
                       "命中","伤害","硬直","击退","暴击","动作","动画","闪避","冲刺",
                       "跳跃","位移","判定","受击","格挡"};

        String out = "D:/MeteorProjects/_private/ghidra_scripts/combat_anchor.csv";
        PrintWriter pw = new PrintWriter(new FileOutputStream(out));
        pw.println("keyword,string_addr,string_value,func_entry,func_name,func_size");

        int rows = 0;
        Iterator<Data> it = listing.getDefinedData(true);
        while (it.hasNext()) {
            Data d = it.next();
            Object val = d.getValue();
            if (!(val instanceof String)) continue;
            String s = (String) val;
            if (s.length() < 2) continue;
            String sl = s.toLowerCase();
            String matched = null;
            for (String k : en) { if (sl.contains(k)) { matched = k; break; } }
            if (matched == null) {
                for (String c : cn) { if (s.contains(c)) { matched = c; break; } }
            }
            if (matched == null) continue;
            Address strAddr = d.getAddress();
            ReferenceIterator refs = refMgr.getReferencesTo(strAddr);
            while (refs.hasNext()) {
                Reference r = refs.next();
                Address from = r.getFromAddress();
                Function f = fm.getFunctionContaining(from);
                String fe = (f == null) ? "" : f.getEntryPoint().toString();
                String fn = (f == null) ? "(none)" : f.getName();
                long fs = (f == null) ? 0 : f.getBody().getNumAddresses();
                pw.printf("%s,%s,%s,%s,%s,%d%n",
                    matched, strAddr.toString(),
                    s.replace(",", " ").replace("\n", " ").replace("\r", " "),
                    fe, fn, fs);
                rows++;
            }
        }
        pw.close();
        printf("CombatAnchor done. rows=%d -> %s\n", rows, out);
    }
}
