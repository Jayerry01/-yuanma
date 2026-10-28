void FUN_004eb870(float *param_1,short param_2,short *param_3,int param_4,int param_5)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  
  fVar1 = 1.0 / (float)(int)param_2;
  if (param_5 == 0) {
    if (0 < param_4) {
      do {
        param_4 = param_4 + -1;
        *param_1 = (float)(int)*param_3 * fVar1;
        param_1[1] = (float)(int)param_3[1] * fVar1;
        param_1[2] = (float)(int)param_3[2] * fVar1;
        param_3 = param_3 + 3;
        param_1 = param_1 + 8;
      } while (param_4 != 0);
    }
  }
  else {
    fVar2 = 1.0 / (float)param_5;
    if (0 < param_4) {
      do {
        *param_1 = (float)(int)*param_3 * fVar1;
        param_1[1] = (float)(int)param_3[1] * fVar1;
        param_1[2] = (float)(int)param_3[2] * fVar1;
        if ((*(byte *)((int)param_3 + 9) & 1) == 0) {
          uVar3 = (uint)*(byte *)(param_3 + 3);
        }
        else {
          uVar3 = -(uint)*(byte *)(param_3 + 3);
        }
        param_1[3] = (float)(int)uVar3 * fVar2;
        if ((*(byte *)((int)param_3 + 9) & 2) == 0) {
          uVar3 = (uint)*(byte *)((int)param_3 + 7);
        }
        else {
          uVar3 = -(uint)*(byte *)((int)param_3 + 7);
        }
        param_1[4] = (float)(int)uVar3 * fVar2;
        if ((*(byte *)((int)param_3 + 9) & 4) == 0) {
          uVar3 = (uint)*(byte *)(param_3 + 4);
        }
        else {
          uVar3 = -(uint)*(byte *)(param_3 + 4);
        }
        param_3 = param_3 + 5;
        param_4 = param_4 + -1;
        param_1[5] = (float)(int)uVar3 * fVar2;
        param_1 = param_1 + 8;
      } while (param_4 != 0);
      return;
    }
  }
  return;
}



bool __thiscall