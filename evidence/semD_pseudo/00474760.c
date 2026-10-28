undefined4 FUN_00474760(undefined4 param_1)

{
  int iVar1;
  DWORD DStack_2c;
  
  FUN_0052c580();
  FUN_0052bf30();
  thunk_FUN_00531020();
  FUN_0052b0b0(0x600);
  FUN_0052bc60(0x601);
  if (DAT_005e03a4 == 0) {
    FUN_00474610();
  }
  iVar1 = (*(code *)PTR_FUN_005c7c60)(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  FUN_00478c90();
  FUN_00474700();
  FUN_0047b270();
  _DAT_005e0414 = 1;
  FUN_00477200();
  FUN_00474530(&DAT_005e0568,0x3f860a92,0x3f800000,0x3f800000,0x447a0000);
  FUN_0047b1b0();
  FUN_0047ae40(param_1);
  EnumDisplaySettingsA((LPCSTR)0x0,0xffffffff,(DEVMODEA *)&stack0xffffff6c);
  _DAT_005e039c = DStack_2c;
  FUN_00478e70(DStack_2c);
  if (DAT_005e03e4 < DAT_005c8114) {
    DAT_005c8114 = DAT_005e03e4;
  }
  if (DAT_005e03e8 < DAT_005c8118) {
    DAT_005c8118 = DAT_005e03e8;
  }
  FUN_00475aa0();
  return 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
