undefined4 __fastcall FUN_004b9ae0(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int **)(param_1 + 0x3bc) != (int *)0x0) &&
     (*(int **)(param_1 + 0x3bc) != *(int **)(param_1 + 0x3b8))) {
    (**(code **)(**(int **)(param_1 + 0x3b8) + 0x14))(param_1);
    (**(code **)(**(int **)(param_1 + 0x3bc) + 0x18))(param_1);
    uVar1 = *(undefined4 *)(param_1 + 0x3b8);
    *(undefined4 *)(param_1 + 0x3b8) = *(undefined4 *)(param_1 + 0x3bc);
    *(undefined4 *)(param_1 + 0x3bc) = uVar1;
    return 1;
  }
  return 0;
}


