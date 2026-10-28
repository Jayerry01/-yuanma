undefined4 FUN_0052f800(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  bVar1 = false;
  DAT_007232a4 = (uint *)FUN_0052c490();
  DAT_007dcb80 = DAT_007232a4;
  if (DAT_007232a4 == (uint *)0x0) {
    FUN_00530d00(0x506);
    return 0;
  }
  if (DAT_007232a4[0x10] != 0) {
    FUN_0052c1a0(DAT_007232a4[0x10]);
    DAT_007dcb80[0x10] = 0;
  }
  DAT_007dcb80[0x14] = 0;
  uVar2 = FUN_00531000(*DAT_007232a4);
  uVar3 = FUN_00531000(DAT_007232a4[1]);
  if ((*DAT_007232a4 != uVar2) || (DAT_007232a4[1] != uVar3)) {
    bVar1 = true;
    uVar4 = FUN_0052c490();
    uVar4 = FUN_0052cce0(uVar4);
    FUN_0052c4a0(uVar4);
    FUN_0052f7a0(0x2600,0x2603);
    FUN_0052daa0(uVar2,uVar3,1);
    FUN_0052f7a0(0x2600,DAT_005cfe18);
    DAT_007232a4 = (uint *)FUN_0052c490();
  }
  DAT_00723290 = 0;
  FUN_0052fd70(*DAT_007232a4 >> 1,DAT_007232a4[1] >> 1);
  if (bVar1) {
    DAT_007dcb80[0x10] = DAT_007232a4[0x10];
    DAT_007232a4[0x10] = 0;
    FUN_0052c1a0(DAT_007232a4);
    FUN_0052c4a0(DAT_007dcb80);
  }
  return 1;
}


