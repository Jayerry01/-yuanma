undefined1 __thiscall FUN_0056a8a0(int param_1,int param_2)

{
  undefined1 uVar1;
  
  if (*(char *)(param_1 + 0x131) == '\0') {
    return 1;
  }
  if (*(char *)(param_2 + 0x21d) != '\0') {
    return *(undefined1 *)(param_2 + 0x21c);
  }
  *(undefined1 *)(param_2 + 0x21d) = 1;
  uVar1 = FUN_00474990(param_2 + 0x250);
  *(undefined1 *)(param_2 + 0x21c) = uVar1;
  return uVar1;
}


