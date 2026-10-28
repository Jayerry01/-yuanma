uint FUN_004748d0(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  float *pfVar5;
  int iVar6;
  
  uVar4 = 0;
  if (DAT_005e04d4 != 0) {
    iVar6 = 0;
    pfVar5 = (float *)&DAT_005e08bc;
    do {
      if (pfVar5[-2] <= 0.0) {
        fVar1 = *param_2;
        if (0.0 < pfVar5[-1]) goto LAB_00474938;
        fVar2 = param_2[1];
LAB_0047493b:
        if (*pfVar5 <= 0.0) {
LAB_0047494c:
          fVar3 = param_2[2];
        }
        else {
          fVar3 = param_1[2];
        }
      }
      else {
        fVar1 = *param_1;
        if (0.0 < pfVar5[-1]) {
LAB_00474938:
          fVar2 = param_1[1];
          goto LAB_0047493b;
        }
        fVar2 = param_2[1];
        if (*pfVar5 <= 0.0) goto LAB_0047494c;
        fVar3 = param_1[2];
      }
      fVar1 = fVar1 * pfVar5[-2] + fVar2 * pfVar5[-1] + fVar3 * *pfVar5 + pfVar5[1];
      uVar4 = (uint)(ushort)((ushort)(fVar1 < 0.0) << 8 | (ushort)(fVar1 == 0.0) << 0xe);
      if (fVar1 >= 0.0 && (fVar1 == 0.0) == 0) {
        return uVar4;
      }
      pfVar5 = pfVar5 + 4;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 6);
  }
  return CONCAT31((int3)(uVar4 >> 8),1);
}


