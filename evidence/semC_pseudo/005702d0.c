float FUN_005702d0(int param_1,int param_2,float *param_3,float *param_4,float *param_5,
                  float param_6)

{
  float fVar1;
  undefined4 uVar2;
  bool bVar3;
  float fVar4;
  float *pfVar5;
  ushort uVar7;
  float fVar6;
  int iVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  float10 fVar12;
  float local_24 [9];
  
  param_1 = param_1 - (int)param_3;
  bVar3 = true;
  local_24[3] = *param_4 - *param_3;
  local_24[4] = param_4[1] - param_3[1];
  local_24[0] = *param_4 - *param_3;
  param_2 = param_2 - (int)param_3;
  local_24[1] = param_4[1] - param_3[1];
  local_24[5] = param_4[2] - param_3[2];
  local_24[2] = param_4[2] - param_3[2];
  iVar8 = 0;
  iVar9 = (int)local_24 + (0x18 - (int)param_3);
  pfVar5 = param_3;
  do {
    if (*(float *)(param_1 + (int)pfVar5) <= *pfVar5) {
      if (*pfVar5 <= *(float *)(param_2 + (int)pfVar5)) {
        *(undefined1 *)((int)&param_4 + iVar8) = 2;
      }
      else {
        *(undefined1 *)((int)&param_4 + iVar8) = 3;
        bVar3 = false;
        *(undefined4 *)((int)pfVar5 + iVar9) = *(undefined4 *)(param_2 + (int)pfVar5);
      }
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + (int)pfVar5);
      *(undefined1 *)((int)&param_4 + iVar8) = 1;
      *(undefined4 *)((int)pfVar5 + iVar9) = uVar2;
      bVar3 = false;
    }
    iVar8 = iVar8 + 1;
    pfVar5 = pfVar5 + 1;
  } while (iVar8 < 3);
  if (bVar3) {
    *param_5 = *param_3;
    fVar6 = param_3[1];
    param_5[1] = fVar6;
    param_5[2] = param_3[2];
  }
  else {
    pfVar5 = local_24;
    iVar8 = 0;
    iVar10 = (int)param_3 - (int)pfVar5;
    do {
      if (*(char *)((int)&param_4 + iVar8) == '\x02') {
LAB_005703de:
        local_24[iVar8 + 3] = -1.0;
      }
      else {
        pfVar5 = (float *)((uint)pfVar5 & 0xffff0000);
        if (local_24[iVar8] == 0.0) goto LAB_005703de;
        pfVar5 = (float *)(iVar10 + (int)(local_24 + iVar8));
        local_24[iVar8 + 3] = (*(float *)((int)pfVar5 + iVar9) - *pfVar5) / local_24[iVar8];
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 3);
    iVar8 = 0;
    iVar10 = 1;
    param_4 = (float *)0x0;
    do {
      uVar7 = (ushort)((uint)pfVar5 >> 0x10);
      pfVar5 = (float *)((uint)uVar7 << 0x10);
      if (*(float *)((int)local_24 + iVar8 + 0xc) < local_24[iVar10 + 3]) {
        param_4 = (float *)iVar10;
        iVar8 = iVar10 * 4;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < 3);
    fVar6 = local_24[(int)param_4 + 3];
    if (fVar6 < 0.0) {
      return (float)CONCAT22(uVar7,(ushort)(fVar6 < 0.0) << 8 | (ushort)NAN(fVar6) << 10 |
                                   (ushort)(fVar6 == 0.0) << 0xe);
    }
    iVar8 = 0;
    pfVar5 = param_3;
    do {
      if (param_4 == (float *)iVar8) {
        fVar6 = *(float *)((int)pfVar5 + iVar9);
        *(float *)(((int)param_5 - (int)param_3) + (int)pfVar5) = fVar6;
      }
      else {
        fVar4 = *(float *)(((int)local_24 - (int)param_3) + (int)pfVar5) *
                local_24[(int)param_4 + 3] + *pfVar5;
        *(float *)(((int)param_5 - (int)param_3) + (int)pfVar5) = fVar4;
        fVar6 = *(float *)((int)pfVar5 + param_1);
        if (fVar4 < fVar6) {
          return (float)CONCAT22((short)((uint)param_1 >> 0x10),
                                 (ushort)(fVar4 < fVar6) << 8 |
                                 (ushort)(NAN(fVar4) || NAN(fVar6)) << 10 |
                                 (ushort)(fVar4 == fVar6) << 0xe);
        }
        fVar1 = *(float *)((int)pfVar5 + param_2);
        fVar6 = (float)(uint)(ushort)((ushort)(fVar4 < fVar1) << 8 | (ushort)(fVar4 == fVar1) << 0xe
                                     );
        if (fVar4 >= fVar1 && (fVar4 == fVar1) == 0) {
          return fVar6;
        }
      }
      iVar8 = iVar8 + 1;
      pfVar5 = pfVar5 + 1;
    } while (iVar8 < 3);
    fVar6 = (float)CONCAT31((int3)((uint)fVar6 >> 8),param_6._0_1_);
    if (param_6._0_1_ == '\0') {
      local_24[3] = *param_5 - *param_3;
      local_24[4] = param_5[1] - param_3[1];
      local_24[5] = param_5[2] - param_3[2];
      local_24[6] = local_24[3];
      local_24[7] = local_24[4];
      local_24[8] = local_24[5];
      fVar11 = (float10)FUN_0047ecf0();
      param_6 = (float)fVar11;
      fVar12 = (float10)FUN_0047ecf0();
      fVar11 = (float10)param_6;
      fVar6 = (float)(uint)(ushort)((ushort)(fVar12 < fVar11) << 8 |
                                   (ushort)(fVar12 == fVar11) << 0xe);
      if (fVar12 >= fVar11 && (fVar12 == fVar11) == 0) {
        return fVar6;
      }
    }
  }
  return (float)CONCAT31((int3)((uint)fVar6 >> 8),1);
}


