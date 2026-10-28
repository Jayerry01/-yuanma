undefined4 FUN_0047d000(float param_1,float param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float local_c;
  float local_8;
  float local_4;
  
  iVar8 = FUN_0047c1e0((DAT_005c8128 + 1) * (DAT_005c8124 + 1),DAT_005c8128 * DAT_005c8124 * 2,
                       DAT_005c8128 * DAT_005c8124 * 6);
  if (iVar8 != 0) {
    fVar4 = param_3 - param_2;
    iVar8 = 0;
    fVar5 = (float)DAT_005c8124;
    fVar6 = param_5 - param_4;
    fVar7 = (float)DAT_005c8128;
    param_5 = param_2 * 0.017453292;
    FUN_00481b30();
    param_2 = 0.0;
    if (-1 < DAT_005c8124) {
      fVar3 = param_4 * 0.017453292;
      iVar9 = DAT_005c8128;
      do {
        fVar12 = (float10)fcos((float10)param_5);
        param_4 = 0.0;
        fVar13 = (float10)fsin((float10)param_5);
        if (-1 < iVar9) {
          param_3 = fVar3;
          do {
            fVar14 = (float10)fcos((float10)param_3);
            fVar15 = (float10)fsin((float10)param_3);
            fVar1 = (float)((float10)(float)(fVar12 * (float10)param_1) * fVar15);
            fVar2 = (float)((float10)(float)(fVar12 * (float10)param_1) * fVar14);
            FUN_00481c20(iVar8,fVar2,fVar1,(float)fVar13 * param_1);
            local_c = fVar2;
            local_8 = fVar1;
            local_4 = (float)fVar13 * param_1;
            FUN_0047ec40();
            FUN_00481c60(iVar8,&local_c);
            FUN_00481d00(iVar8,0xffffffff);
            FUN_00481d40(iVar8,(float)(int)param_4 / (float)DAT_005c8128,
                         (float)(int)param_2 / (float)DAT_005c8124,0xffffffff);
            param_3 = param_3 + (fVar6 * 0.017453292) / fVar7;
            param_4 = (float)((int)param_4 + 1);
            iVar8 = iVar8 + 1;
            iVar9 = DAT_005c8128;
          } while ((int)param_4 <= DAT_005c8128);
        }
        param_5 = param_5 + (fVar4 * 0.017453292) / fVar5;
        param_2 = (float)((int)param_2 + 1);
      } while ((int)param_2 <= DAT_005c8124);
    }
    FUN_00481b90();
    iVar11 = 0;
    iVar9 = 0;
    FUN_00481b30();
    param_2 = 0.0;
    iVar8 = DAT_005c8128;
    if (0 < DAT_005c8124) {
      do {
        param_4 = 0.0;
        iVar10 = iVar9;
        if (0 < iVar8) {
          do {
            iVar10 = iVar10 + 1;
            FUN_00481ee0(iVar11,iVar9);
            FUN_00481ee0(iVar11 + 1,iVar10);
            FUN_00481ee0(iVar11 + 2,DAT_005c8128 + 1 + iVar9);
            FUN_00481ee0(iVar11 + 3,iVar10);
            iVar8 = iVar11 + 5;
            FUN_00481ee0(iVar11 + 4,DAT_005c8128 + 2 + iVar9);
            iVar11 = iVar11 + 6;
            FUN_00481ee0(iVar8,DAT_005c8128 + 1 + iVar9);
            iVar9 = iVar9 + 1;
            param_4 = (float)((int)param_4 + 1);
            iVar8 = DAT_005c8128;
          } while ((int)param_4 < DAT_005c8128);
        }
        iVar9 = iVar9 + 1;
        param_2 = (float)((int)param_2 + 1);
      } while ((int)param_2 < DAT_005c8124);
    }
    FUN_00481b90();
    return 1;
  }
  return 0;
}


