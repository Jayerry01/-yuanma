void __fastcall FUN_004badd0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int unaff_EBX;
  
  piVar1 = (int *)(param_1 + -0x10);
  (**(code **)(*(int *)(param_1 + -0x10) + 0x1ac))(4);
  (**(code **)(*piVar1 + 0x100))();
  piVar2 = (int *)FUN_00487830();
  (**(code **)(*piVar2 + 0x1b8))();
  (**(code **)(*piVar1 + 0x1ac))(1);
  FUN_004b2ef0(unaff_EBX);
  if (unaff_EBX == 0x81) {
    (**(code **)(*piVar1 + 0x80))(s_The_End____005c9a40);
  }
  iVar3 = FUN_00487830();
  (**(code **)(*piVar1 + 0x80))(*(undefined4 *)(*(int *)(iVar3 + 0x2448) + 0x24));
  return;
}


