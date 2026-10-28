undefined4 __thiscall FUN_004dbb60(int param_1,byte param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((param_2 & 1) != 0) && (*(int **)(param_1 + 0x820) != (int *)0x0)) {
    (**(code **)(**(int **)(param_1 + 0x820) + 8))(1);
    uVar1 = 1;
    *(undefined4 *)(param_1 + 0x820) = 0;
  }
  if (((param_2 & 2) != 0) && (*(int **)(param_1 + 0x81c) != (int *)0x0)) {
    (**(code **)(**(int **)(param_1 + 0x81c) + 8))(1);
    uVar1 = 1;
    *(undefined4 *)(param_1 + 0x81c) = 0;
  }
  if (((param_2 & 4) != 0) && (*(int **)(param_1 + 0x824) != (int *)0x0)) {
    (**(code **)(**(int **)(param_1 + 0x824) + 8))(1);
    uVar1 = 1;
    *(undefined4 *)(param_1 + 0x824) = 0;
  }
  if (((param_2 & 8) != 0) && (*(int **)(param_1 + 0x828) != (int *)0x0)) {
    (**(code **)(**(int **)(param_1 + 0x828) + 8))(1);
    uVar1 = 1;
    *(undefined4 *)(param_1 + 0x828) = 0;
  }
  return uVar1;
}



undefined4 __thiscall