undefined4 __fastcall FUN_004b8d70(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = FUN_004a93c0();
  piVar1 = (int *)(param_1 + 0x14);
  if (*(int *)(param_1 + 0x18) != 0) {
    iVar3 = *(int *)(*piVar1 + 4);
    while (iVar3 != 0) {
      FUN_004b8ee0(*(undefined4 *)(iVar3 + 0xc));
      iVar2 = *(int *)(iVar3 + 8);
      FUN_00402e90(iVar3,0x18);
      iVar3 = iVar2;
    }
    *(int *)(*piVar1 + 8) = *piVar1;
    *(undefined4 *)(*piVar1 + 4) = 0;
    *(int *)(*piVar1 + 0xc) = *piVar1;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return uVar4;
}


