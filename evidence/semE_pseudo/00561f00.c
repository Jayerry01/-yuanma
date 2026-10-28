undefined4 __thiscall FUN_00561f00(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x250) == '\0') {
    return 0;
  }
  cVar1 = FUN_0056d8c0(param_2,1);
  if (cVar1 == '\0') {
    *(undefined4 *)(param_1 + 0x4b8) = 0;
  }
  else {
    uVar2 = FUN_00561cf0(param_2);
    *(undefined4 *)(param_1 + 0x4b8) = uVar2;
  }
  if (*(int *)(param_1 + 0x4bc) != *(int *)(param_1 + 0x4b8)) {
    FUN_00561f90();
  }
  return 1;
}


