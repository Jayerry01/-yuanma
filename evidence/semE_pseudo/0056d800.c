undefined4 __thiscall FUN_0056d800(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x214);
  }
  else {
    if (param_2 == 1) {
      return *(undefined4 *)(param_1 + 0x218);
    }
    if (param_2 == 2) {
      return *(undefined4 *)(param_1 + 0x21c);
    }
  }
  return uVar1;
}


