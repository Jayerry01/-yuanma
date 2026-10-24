import ghidra.app.script.GhidraScript;
import ghidra.app.util.exporter.CppExporter;
import java.io.File;

public class ExportAllCpp extends GhidraScript {
    @Override
    public void run() throws Exception {
        File outDir = new File("D:/MeteorRE/decompiled_full");
        if (!outDir.exists()) {
            outDir.mkdirs();
        }
        File outFile = new File(outDir, "Meteor_all_functions.c");
        println("[ExportAllCpp] Starting CppExporter to: " + outFile.getAbsolutePath());
        long start = System.currentTimeMillis();
        
        CppExporter exporter = new CppExporter();
        boolean success = exporter.export(outFile, currentProgram, null, monitor);
        
        long elapsed = System.currentTimeMillis() - start;
        println("[ExportAllCpp] Finished in " + (elapsed / 1000) + "s. Success: " + success + ", File size: " + outFile.length() + " bytes");
    }
}
