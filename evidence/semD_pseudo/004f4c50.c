undefined4 __fastcall FUN_004f4c50(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *unaff_retaddr;
  
  piVar1 = (int *)FUN_00487830();
  (**(code **)(*piVar1 + 0x2e4))();
  piVar1 = (int *)FUN_00487830();
  (**(code **)(*piVar1 + 0x39c))(1);
  iVar2 = (**(code **)(*unaff_retaddr + 0x134))();
  piVar1 = (int *)FUN_00487830();
  iVar3 = (**(code **)(*piVar1 + 0x284))(1);
  piVar1 = (int *)FUN_00487830();
  iVar4 = (**(code **)(*piVar1 + 0x284))(2);
  *(undefined4 *)(param_1 + 0x50) = 4;
  if (iVar2 != 0) {
    iVar5 = (**(code **)(*unaff_retaddr + 0x1dc))();
    if (iVar5 == 0) {
      if (*(int *)(iVar2 + 0x1f0) == 1) {
        if (iVar4 < iVar3) {
          *(undefined4 *)(param_1 + 0x50) = 1;
        }
        else {
          *(uint *)(param_1 + 0x50) = (iVar3 == iVar4) + 2;
        }
      }
      else if (*(int *)(iVar2 + 0x1f0) == 2) {
        if (iVar4 < iVar3) {
          *(undefined4 *)(param_1 + 0x50) = 2;
        }
        else {
          *(uint *)(param_1 + 0x50) = (uint)(iVar3 == iVar4) * 2 + 1;
        }
      }
    }
  }
  *(undefined4 *)(param_1 + 4) = 1;
  FUN_00549a90(0,0);
  return 1;
}


