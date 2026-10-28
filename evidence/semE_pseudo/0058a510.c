undefined4 __thiscall FUN_0058a510(int param_1,int param_2)

{
  undefined4 uVar1;
  
  FUN_00583350(param_2);
  if (*(int *)(param_1 + 0x10) == 0) {
    *(undefined4 *)(param_2 + 0x10) = 0;
  }
  else {
    uVar1 = FUN_005056d0(*(int *)(param_1 + 0x10));
    *(undefined4 *)(param_2 + 0x10) = uVar1;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x27c);
  *(undefined4 *)(param_2 + 0x278) = 0;
  *(undefined4 *)(param_2 + 0x27c) = uVar1;
  return 1;
}


