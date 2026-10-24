@echo off
set "JAVA_HOME=D:\tools\jdk-21.0.12.1+1"
set "PATH=%JAVA_HOME%\bin;%PATH%"
call "D:\tools\ghidra_12.1.4_PUBLIC\support\analyzeHeadless.bat" "D:\MeteorRE\ghidra_proj" "MeteorProj" -import "D:\MeteorRE\Meteor.exe" -overwrite -scriptPath "D:\MeteorRE\tools" -postScript "ExportAllCpp.java" -max-cpu 16
