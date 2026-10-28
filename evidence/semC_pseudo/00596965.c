FUN_00596965(undefined4 *param_1,int param_2,double *param_3,int param_4,undefined4 *param_5,
            int param_6,int param_7,int param_8,uint param_9)

{
  double *pdVar1;
  double *pdVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int iVar5;
  uint local_20;
  uint local_1c;
  undefined4 local_14;
  
  pdVar1 = _malloc(param_9 << 3);
  pdVar2 = _malloc(param_9 << 3);
  pvVar3 = _malloc(param_9 << 3);
  puVar4 = _malloc(param_9 << 3);
  if ((((pdVar1 == (double *)0x0) || (pdVar2 == (double *)0x0)) || (pvVar3 == (void *)0x0)) ||
     (puVar4 == (undefined4 *)0x0)) {
    local_14 = 8;
  }
  else {
    *(undefined4 *)pdVar2 = *param_1;
    *(undefined4 *)((int)pdVar2 + 4) = param_1[1];
    *pdVar1 = *param_3 / *pdVar2;
    for (local_1c = 1; local_1c < param_9 - 1; local_1c = local_1c + 1) {
      pdVar2[local_1c] =
           *(double *)(param_1 + param_2 * local_1c * 2) -
           param_3[param_4 * (local_1c - 1)] * pdVar1[local_1c - 1];
      pdVar1[local_1c] = param_3[param_4 * local_1c] / pdVar2[local_1c];
    }
    if (1 < param_9) {
      pdVar2[param_9 - 1] =
           *(double *)(param_1 + param_2 * (param_9 - 1) * 2) -
           param_3[param_4 * (param_9 - 2)] * pdVar1[param_9 - 2];
    }
    *puVar4 = *param_5;
    puVar4[1] = param_5[1];
    for (local_1c = 1; local_1c < param_9; local_1c = local_1c + 1) {
      *(double *)(puVar4 + local_1c * 2) =
           *(double *)(param_5 + param_6 * local_1c * 2) -
           pdVar1[local_1c - 1] * *(double *)(puVar4 + local_1c * 2 + -2);
    }
    for (local_1c = 0; local_1c < param_9; local_1c = local_1c + 1) {
      *(double *)((int)pvVar3 + local_1c * 8) =
           *(double *)(puVar4 + local_1c * 2) / pdVar2[local_1c];
    }
    iVar5 = param_8 * (param_9 - 1);
    *(undefined4 *)(param_7 + iVar5 * 8) = *(undefined4 *)((int)pvVar3 + param_9 * 8 + -8);
    *(undefined4 *)(param_7 + 4 + iVar5 * 8) = *(undefined4 *)((int)pvVar3 + param_9 * 8 + -4);
    if (1 < param_9) {
      local_1c = param_9 - 2;
      for (local_20 = 0; local_20 <= param_9 - 2; local_20 = local_20 + 1) {
        *(double *)(param_7 + param_8 * local_1c * 8) =
             *(double *)((int)pvVar3 + local_1c * 8) -
             pdVar1[local_1c] * *(double *)(param_7 + param_8 * (local_1c + 1) * 8);
        local_1c = local_1c + -1;
      }
    }
    local_14 = 0;
  }
  if (puVar4 != (undefined4 *)0x0) {
    FUN_005089fd(puVar4);
  }
  if (pvVar3 != (void *)0x0) {
    FUN_005089fd(pvVar3);
  }
  if (pdVar2 != (double *)0x0) {
    FUN_005089fd(pdVar2);
  }
  if (pdVar1 != (double *)0x0) {
    FUN_005089fd(pdVar1);
  }
  return local_14;
}


