void __thiscall FUN_005513e0(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  piVar1 = param_2;
  if ((*(int *)(param_1 + 0x610) != 0) && (*(int *)(param_1 + 8) == 0)) {
    *(undefined1 *)(param_1 + 0x67c) = 1;
    FUN_00550210(*(undefined4 *)(param_1 + 0x638),*(undefined4 *)(param_1 + 0x644));
    return;
  }
  iVar3 = (param_2[1] - *param_2) / 0x14;
  if (0 < iVar3) {
    FUN_005558f0();
    param_2 = (int *)0x1;
    FUN_00555950(&param_2,2);
    param_2 = (int *)iVar3;
    FUN_00555950(&param_2,2);
    if (0 < iVar3) {
      iVar4 = 0;
      do {
        param_2 = *(int **)(iVar4 + *piVar1);
        FUN_00555950(&param_2,4);
        FUN_00555950(*piVar1 + 4 + iVar4,0x10);
        iVar4 = iVar4 + 0x14;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    iVar3 = DAT_00725af4 - DAT_00725af0;
    uVar5 = 0xc;
    uVar2 = FUN_00555930(iVar3,0xc);
    FUN_005534d0(uVar2,iVar3,uVar5);
  }
  return;
}


