uint __fastcall FUN_00501090(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x44))();
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_00501130();
  if ((char)uVar2 != '\0') {
    return uVar2 & 0xffffff00;
  }
  return (uint)((*(uint *)(iVar1 + 0x3c8) & 5) != 0);
}


