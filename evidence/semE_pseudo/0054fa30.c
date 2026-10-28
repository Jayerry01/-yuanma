void __thiscall FUN_0054fa30(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (*(int *)(iVar3 + 4) != 0) {
    iVar1 = *(int *)(iVar3 + 4);
    do {
      if (*(int *)(iVar1 + 0x10) < *param_3) {
        iVar2 = *(int *)(iVar1 + 0xc);
      }
      else {
        iVar2 = *(int *)(iVar1 + 8);
        iVar3 = iVar1;
      }
      iVar1 = iVar2;
    } while (iVar2 != 0);
  }
  *param_2 = iVar3;
  return;
}


