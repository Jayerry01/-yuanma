undefined4 FUN_0052daa0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  DAT_007232a4 = (int *)FUN_0052c490();
  if (DAT_007232a4 == (int *)0x0) {
    FUN_00530d00(0x506);
  }
  else {
    if (((*DAT_007232a4 == param_1) && (DAT_007232a4[1] == param_2)) && (DAT_007232a4[2] == param_3)
       ) {
      return 1;
    }
    if ((0x2603 < DAT_005cfe18) && (DAT_005cfe18 < 0x260a)) {
      uVar5 = FUN_00535fd0(param_1,param_2,DAT_005cfe18);
      return uVar5;
    }
    iVar1 = DAT_007232a4[8];
    iVar2 = DAT_007232a4[10];
    iVar3 = DAT_007232a4[0xd];
    puVar6 = (undefined4 *)FUN_0052db90(DAT_007232a4,param_1,param_2,param_3);
    if (puVar6 != (undefined4 *)0x0) {
      FUN_0052c880(*puVar6,puVar6[1],puVar6[2],
                   CONCAT31((int3)((uint)puVar6[5] >> 8),*(undefined1 *)(puVar6 + 3)),puVar6[8],
                   puVar6[9],puVar6[5]);
      DAT_007232a4[10] = iVar2;
      FUN_0052c1a0(puVar6);
      if (iVar1 == 0x1900) {
        cVar4 = FUN_0052eb20(0x1900,0x1401);
        if (cVar4 == '\0') {
          return 0;
        }
        FUN_00535620(iVar3);
      }
      return 1;
    }
  }
  return 0;
}


