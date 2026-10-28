void __fastcall FUN_004a0550(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x14) != *(int *)(param_1 + 0x10)) {
    uVar1 = __ftol(*(int *)(param_1 + 0x10),0xff,0x78,0x69);
    uVar1 = __ftol(uVar1);
    FUN_00421d00(uVar1);
  }
  return;
}


