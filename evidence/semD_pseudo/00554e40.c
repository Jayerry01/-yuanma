void FUN_00554e40(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 local_8 [8];
  
  FUN_00555800(local_8,(uint *)(param_2 + 0x10),8);
  uVar1 = *(uint *)(param_2 + 0x10) >> 3 & 0x3f;
  iVar2 = 0x38;
  if (0x37 < uVar1) {
    iVar2 = 0x78;
  }
  FUN_00554d90(param_2,&DAT_005d1240,iVar2 - uVar1);
  FUN_00554d90(param_2,local_8,8);
  FUN_00555800(param_1,param_2,0x10);
  FUN_005558c0(param_2,0,0x58);
  return;
}


