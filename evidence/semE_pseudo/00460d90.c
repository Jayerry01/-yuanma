void __thiscall FUN_00460d90(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *param_1;
  iVar4 = iVar1;
  if (*(int *)(iVar1 + 4) != 0) {
    iVar2 = *(int *)(iVar1 + 4);
    do {
      if (*(int *)(iVar2 + 0x10) < *param_3) {
        iVar3 = *(int *)(iVar2 + 0xc);
      }
      else {
        iVar3 = *(int *)(iVar2 + 8);
        iVar4 = iVar2;
      }
      iVar2 = iVar3;
    } while (iVar3 != 0);
  }
  if ((iVar4 != iVar1) && (*(int *)(iVar4 + 0x10) <= *param_3)) {
    *param_2 = iVar4;
    return;
  }
  *param_2 = iVar1;
  return;
}


