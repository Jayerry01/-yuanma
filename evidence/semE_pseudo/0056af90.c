undefined4 __fastcall FUN_0056af90(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x120);
  if (iVar1 == 0) {
    return 0;
  }
  if (((*(char *)(iVar1 + 0x1d) != '\0') && (*(char *)(iVar1 + 0x1e) != '\0')) &&
     (*(char *)(iVar1 + 0x1f) != '\0')) {
    return 1;
  }
  return 0;
}


