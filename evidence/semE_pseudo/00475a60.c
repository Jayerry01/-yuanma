void FUN_00475a60(int param_1)

{
  if (*(int *)(param_1 + 4) == 1) {
    FUN_00475590(0,0);
  }
  if (*(char *)(param_1 + 0x10) != '\0') {
    FUN_00475590(2,1);
  }
  if (*(char *)(param_1 + 0x11) != '\0') {
    FUN_00475590(1,0);
  }
  return;
}


