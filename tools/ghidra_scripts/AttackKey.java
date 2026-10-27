// AttackKey.java - locate the attack/jump input path: remaining input APIs + mouse window messages
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class AttackKey extends GhidraScript {

    PrintWriter out;
    Program prog;

    String[] APIs = {
        "GetKeyState", "GetKeyboardState", "GetAsyncKeyState", "GetSystemMetrics",
        "DirectInput8Create", "DirectInputCreateA", "GetDeviceState", "GetDeviceData",
        "SetCapture", "GetCursorPos", "ShowCursor", "ClipCursor", "mouse_event",
        "GetMessageA", "PeekMessageA", "DispatchMessageA", "TranslateMessage",
        "DefWindowProcA", "CallWindowProcA", "SetWindowsHookExA", "GetRawInputData"
    };

    // WM_LBUTTONDOWN .. WM_MOUSEWHEEL family
    long[] MSGS = {0x200,0x201,0x202,0x203,0x204,0x205,0x206,0x207,0x208,0x209,0x20a,0x20b,0x20c,0x20d,0x20e,0x20f,0x210};

    public void run() throws Exception {
        prog = currentProgram;
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/attackkey.txt")));

        out.println("############ PART 1: input-API IAT slots and their referrers ############");
        SymbolTable st = prog.getSymbolTable();
        for (String api : APIs) {
            List<Symbol> hits = new ArrayList<>();
            for (Symbol s : st.getAllSymbols(true)) {
                if (s.getName().equalsIgnoreCase(api) || s.getName().equalsIgnoreCase(api + "@@")
                    || s.getName().startsWith(api)) hits.add(s);
            }
            if (hits.isEmpty()) continue;
            for (Symbol s : hits) {
                out.println("\n== " + api + "  symbol=" + s.getName() + " @ " + s.getAddress());
                Reference[] refs = getReferencesTo(s.getAddress());
                if (refs.length == 0) { out.println("   (no refs)"); continue; }
                for (Reference r : refs) {
                    Address from = r.getFromAddress();
                    Function f = getFunctionContaining(from);
                    out.println("   ref " + from + "  in " + (f == null ? "<none>" : f.getName() + " size=" + f.getBody().getNumAddresses()));
                }
            }
        }

        out.println("\n\n############ PART 2: mouse/keyboard window-message immediates ############");
        Set<Long> msgSet = new HashSet<>();
        for (long m : MSGS) msgSet.add(m);

        Map<String, List<String>> byFunc = new TreeMap<>();
        Listing lst = prog.getListing();
        for (Function f : lst.getFunctions(true)) {
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            List<Instruction> buf = new ArrayList<>();
            while (it.hasNext()) buf.add(it.next());
            for (int i = 0; i < buf.size(); i++) {
                Instruction ins = buf.get(i);
                for (int op = 0; op < ins.getNumOperands(); op++) {
                    Object[] objs = ins.getOpObjects(op);
                    if (objs == null) continue;
                    for (Object o : objs) {
                        long v;
                        if (o instanceof Scalar) v = ((Scalar) o).getUnsignedValue();
                        else continue;
                        if (!msgSet.contains(v)) continue;
                        // skip obvious PUSH of small constants that are not messages? keep all, tag by size
                        StringBuilder sb = new StringBuilder();
                        sb.append("  @").append(ins.getAddress()).append("  ").append(ins.toString())
                          .append("   [msg 0x").append(Long.toHexString(v)).append("]");
                        String key = f.getName() + " size=" + f.getBody().getNumAddresses();
                        byFunc.computeIfAbsent(key, k -> new ArrayList<>()).add(sb.toString());
                        break;
                    }
                }
            }
        }
        out.println("functions with mouse-message-range immediates: " + byFunc.size());
        for (Map.Entry<String, List<String>> e : byFunc.entrySet()) {
            out.println("\n== " + e.getKey() + "  hits=" + e.getValue().size());
            int n = 0;
            for (String s : e.getValue()) { out.println(s); if (++n >= 14) { out.println("   ..."); break; } }
        }

        out.println("\n\n############ PART 3: who reads the binding table (+0x168 stride 8) ############");
        // look for instructions whose scalar operand is 0x168 or 0x16c on a register base
        Map<String,Integer> off = new TreeMap<>();
        for (Function f : lst.getFunctions(true)) {
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction ins = it.next();
                String t = ins.toString();
                if ((t.contains("+ 0x168") || t.contains("+ 0x16c")) && t.contains("MOV")) {
                    off.merge(f.getName() + " size=" + f.getBody().getNumAddresses()
                              + "  @" + ins.getAddress() + "  " + t, 1, Integer::sum);
                }
            }
        }
        out.println("distinct sites=" + off.size());
        for (String k : off.keySet()) out.println("  " + k);

        out.close();
        println("DONE -> attackkey.txt");
    }
}
