void FUN_0050c74a(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  FUN_0050c7ef();
  if (DAT_006676a4 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_006676a0 = 1;
  DAT_0066769c = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_007f1d80 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_007f1d7c - 4), DAT_007f1d80 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_007f1d80 <= puVar1);
    }
    FUN_0050c801(&DAT_005c4134,&DAT_005c413c);
  }
  FUN_0050c801(&DAT_005c4140,&DAT_005c4148);
  if (param_3 == 0) {
    DAT_006676a4 = 1;
                    // WARNING: Subroutine does not return
    ExitProcess(param_1);
  }
  FUN_0050c7f8();
  return;
}


