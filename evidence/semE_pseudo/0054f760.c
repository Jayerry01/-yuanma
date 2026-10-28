void __thiscall FUN_0054f760(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x9c) == '\0') {
    iVar1 = FUN_00553de0(param_2,param_1);
    if (iVar1 < 0) {
      *(undefined1 *)(param_1 + 0x9c) = 1;
      *(undefined4 *)(param_1 + 0xa0) = 0;
    }
  }
  return;
}


