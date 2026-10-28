undefined4 FUN_0047cdb0(float param_1,float param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  float local_14;
  
  iVar5 = FUN_0047c1e0(DAT_005c8128 * 2 + 2,DAT_005c8128 * 2,DAT_005c8128 * 6);
  if (iVar5 != 0) {
    fVar3 = param_2 - param_1;
    iVar5 = 0;
    fVar4 = (float)DAT_005c8128;
    local_14 = param_1 * 0.017453292;
    FUN_00481b30();
    param_2 = 0.0;
    if (-1 < DAT_005c8128) {
      do {
        fVar9 = (float10)fsin((float10)local_14);
        fVar1 = (float)fVar9;
        fVar9 = (float10)fcos((float10)local_14);
        fVar2 = (float)fVar9;
        FUN_00481c20(iVar5,fVar2 * param_3,fVar1 * param_3,param_5 * -0.5);
        FUN_00481cb0(iVar5,fVar2,fVar1,0);
        FUN_00481d00(iVar5,0xffffffff);
        FUN_00481d40(iVar5,(float)(int)param_2 / (float)DAT_005c8128,0,0xffffffff);
        iVar7 = iVar5 + 1;
        FUN_00481c20(iVar7,fVar2 * param_4,fVar1 * param_4,param_5 * 0.5);
        FUN_00481cb0(iVar7,fVar2,fVar1,0);
        FUN_00481d40(iVar7,(float)(int)param_2 / (float)DAT_005c8128,0x3f800000,0xffffffff);
        local_14 = local_14 + (fVar3 * 0.017453292) / fVar4;
        iVar5 = iVar5 + 2;
        param_2 = (float)((int)param_2 + 1);
      } while ((int)param_2 <= DAT_005c8128);
    }
    FUN_00481b90();
    iVar5 = 0;
    iVar7 = 0;
    FUN_00481b30();
    param_2 = 0.0;
    if (0 < DAT_005c8128) {
      param_1 = 2.8026e-45;
      iVar6 = 1;
      do {
        FUN_00481ee0(iVar7,iVar5);
        FUN_00481ee0(iVar7 + 1,param_1);
        FUN_00481ee0(iVar7 + 2,iVar6);
        FUN_00481ee0(iVar7 + 3,iVar5 + 1);
        iVar8 = iVar7 + 5;
        FUN_00481ee0(iVar7 + 4,iVar6 + 1);
        iVar7 = iVar7 + 6;
        FUN_00481ee0(iVar8,(int)param_1 + 1);
        iVar5 = iVar5 + 2;
        iVar6 = iVar6 + 2;
        param_1 = (float)((int)param_1 + 2);
        param_2 = (float)((int)param_2 + 1);
      } while ((int)param_2 < DAT_005c8128);
    }
    FUN_00481b90();
    return 1;
  }
  return 0;
}


