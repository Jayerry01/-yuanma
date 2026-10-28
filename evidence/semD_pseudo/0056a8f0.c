void __thiscall FUN_0056a8f0(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  
  if (0 < param_3) {
    puVar3 = (undefined4 *)(param_2 + 0x28);
    do {
      cVar2 = FUN_0056a8a0(puVar3[-7]);
      if (cVar2 != '\0') {
        FUN_0056ad30(puVar3 + -10);
        iVar1 = *(int *)(param_1 + 0x120);
        FUN_00475520(0,*(undefined4 *)(iVar1 + 0x100),*(undefined4 *)(iVar1 + 0xe4),
                     *(int *)(iVar1 + 0xfc) + puVar3[-3] * 2,*puVar3,puVar3[-2]);
        FUN_0056adf0(puVar3 + -10);
        *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + puVar3[-2];
        *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + 1;
      }
      puVar3 = puVar3 + 0xc;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}


