void __fastcall FUN_0048b570(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x212c) != 0) {
    FUN_0054e890();
    if (*(undefined4 **)(param_1 + 0x212c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x212c))(1);
    }
    *(undefined4 *)(param_1 + 0x212c) = 0;
  }
  if (*(int *)(param_1 + 0x2130) != 0) {
    FUN_0054e890();
    if (*(undefined4 **)(param_1 + 0x2130) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x2130))(1);
    }
    *(undefined4 *)(param_1 + 0x2130) = 0;
  }
  piVar1 = (int *)FUN_004b3420();
                    // WARNING: Could not recover jumptable at 0x0048b5d5. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(*piVar1 + 8))();
  return;
}


