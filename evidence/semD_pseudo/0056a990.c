void __thiscall FUN_0056a990(int param_1,int param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  
  if (0 < param_3) {
    piVar2 = (int *)(param_2 + 0x20);
    do {
      cVar1 = FUN_0056a8a0(piVar2[-5]);
      if (cVar1 != '\0') {
        FUN_0056ad30(piVar2 + -8);
        FUN_004754f0(0,*(int *)(*(int *)(param_1 + 0x120) + 0x100) + piVar2[-1] * 0x18,*piVar2 * 3,
                     *piVar2);
        FUN_0056adf0(piVar2 + -8);
        *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + *piVar2;
        *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + 1;
      }
      piVar2 = piVar2 + 0xc;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}


