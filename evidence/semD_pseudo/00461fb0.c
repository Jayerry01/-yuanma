void __thiscall FUN_00461fb0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4 [4];
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    FUN_00429990(0);
    FUN_00429aa0(s_mcursor_005c7b70,0,0x20,0x20);
    uVar1 = FUN_00429c30(0);
    *(undefined4 *)(param_1 + 0x1c) = uVar1;
    FUN_00429de0(uVar1,0);
    FUN_00429d80(*(undefined4 *)(param_1 + 0x1c),0xff,0,0,1);
    FUN_00429e60(*(undefined4 *)(param_1 + 0x1c),&local_8,&local_c,local_4);
    FUN_00429d40(*(undefined4 *)(param_1 + 0x1c),local_8,local_c,10);
  }
  FUN_00429de0(*(undefined4 *)(param_1 + 0x1c),param_2);
  return;
}


