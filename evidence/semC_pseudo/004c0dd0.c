void __fastcall FUN_004c0dd0(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 local_40 [64];
  
  if (*(int *)(param_1 + 0x58c) != 0) {
    FUN_00477200();
    iVar1 = FUN_00474600();
    if (iVar1 == 1) {
      FUN_00474570(1);
      FUN_00474410();
      FUN_004745d0(local_40);
    }
    FUN_00474570(3);
    FUN_00474410();
    FUN_004745d0(local_40);
    FUN_00501e60(0);
    FUN_00501fe0();
    iVar2 = *(int *)(param_1 + 0x51c) - *(int *)(param_1 + 0x518);
    uVar3 = 0;
    iVar1 = iVar2 >> 0x1f;
    if (iVar2 / 0x124 + iVar1 != iVar1) {
      iVar1 = 0;
      do {
        iVar2 = *(int *)(param_1 + 0x518) + iVar1;
        if ((-1 < *(int *)(iVar2 + 8)) && (0 < *(int *)(iVar2 + 0x48))) {
          FUN_00501e70();
          FUN_00501f70(0x39c49ba6,0x3a03126f,0x3f800000);
          FUN_00501f30(-*(float *)(*(int *)(param_1 + 0x58c) + 0x3c),0,0,0x3f800000);
          FUN_00501f00(*(float *)(*(int *)(param_1 + 0x58c) + 0x18) - *(float *)(iVar2 + 0x18),
                       *(float *)(*(int *)(param_1 + 0x58c) + 0x1c) - *(float *)(iVar2 + 0x1c),0);
          if (*(int *)(iVar2 + 0x4c) == 1) {
            uVar6 = 0x3f800000;
            uVar5 = 0;
            uVar4 = 0;
          }
          else {
            uVar6 = 0;
            if (*(int *)(iVar2 + 0x4c) == 2) {
              uVar5 = 0;
            }
            else {
              uVar5 = 0x3f800000;
            }
            uVar4 = 0x3f800000;
          }
          FUN_00501c90(uVar4,uVar5,uVar6);
          FUN_005019e0(7);
          FUN_00501b40(0x41a00000,0,0);
          FUN_00501b40(0,0x41a00000,0);
          FUN_00501b40(0xc1a00000,0,0);
          FUN_00501b40(0,0xc1a00000,0);
          FUN_00501a20();
          FUN_00501ec0();
        }
        uVar3 = uVar3 + 1;
        iVar1 = iVar1 + 0x124;
      } while (uVar3 < (uint)((*(int *)(param_1 + 0x51c) - *(int *)(param_1 + 0x518)) / 0x124));
    }
    FUN_00474570(3);
    FUN_00474470();
    iVar1 = FUN_00474600();
    if (iVar1 == 1) {
      FUN_00474570(1);
      FUN_00474470();
      return;
    }
  }
  return;
}


