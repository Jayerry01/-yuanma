
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f4ab0(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  float10 fVar3;
  float fVar4;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  FUN_0054ab30();
  if (*(int *)(param_1 + 4) != 0) {
    fVar3 = (float10)FUN_00549b00();
    if ((float10)_DAT_005a8468 < fVar3) {
      *(undefined4 *)(param_1 + 4) = 0;
      piVar1 = (int *)FUN_00487830();
      (**(code **)(*piVar1 + 0x3a0))(*(undefined4 *)(param_1 + 0x50));
      iVar2 = (**(code **)(*param_2 + 0x134))();
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0x1e8) == 1)) {
        piVar1 = (int *)(**(code **)(*param_2 + 0x44))();
        (**(code **)(*piVar1 + 0x48))(0x20,0x3f800000,0,0xbf800000);
        piVar1 = (int *)(**(code **)(*param_2 + 0x44))();
        (**(code **)(*piVar1 + 100))();
      }
    }
  }
  uStack_8 = 0;
  uStack_4 = 0;
  FUN_005499a0(&uStack_8);
  iVar2 = FUN_00487830();
  *(undefined4 *)(iVar2 + 0x2444) = 1;
  (**(code **)(*param_2 + 0x14c))();
  piVar1 = (int *)FUN_00487830();
  fVar4 = (float)(double)CONCAT44(uStack_4,uStack_8);
  (**(code **)(*piVar1 + 0x1cc))(fVar4);
  piVar1 = (int *)FUN_00487830();
  (**(code **)(*piVar1 + 0x1d0))((float)(double)CONCAT44(uStack_8,unaff_ESI));
  piVar1 = (int *)FUN_00487830();
  (**(code **)(*piVar1 + 0x16c))((float)(double)CONCAT44(unaff_ESI,unaff_EDI));
  piVar1 = (int *)FUN_00487830();
  (**(code **)(*piVar1 + 0x2d0))((float)(double)CONCAT44(unaff_EDI,fVar4));
  iVar2 = FUN_005499a0(0);
  if (iVar2 != 0) {
    (**(code **)(*param_2 + 0x88))();
  }
  return;
}

