FUN_00596c8d(undefined4 *param_1,int param_2,double *param_3,int param_4,undefined4 *param_5,
            int param_6,int param_7,int param_8,uint param_9)

{
  double *pdVar1;
  double *pdVar2;
  double *pdVar3;
  void *pvVar4;
  undefined4 *puVar5;
  int iVar6;
  uint local_2c;
  uint local_28;
  double local_24;
  undefined4 local_18;
  
  pdVar1 = _malloc(param_9 << 3);
  pdVar2 = _malloc(param_9 << 3);
  pdVar3 = _malloc(param_9 << 3);
  pvVar4 = _malloc(param_9 << 3);
  puVar5 = _malloc(param_9 << 3);
  if ((((pdVar1 == (double *)0x0) || (pdVar2 == (double *)0x0)) || (pdVar3 == (double *)0x0)) ||
     ((pvVar4 == (void *)0x0 || (puVar5 == (undefined4 *)0x0)))) {
    local_18 = 8;
  }
  else {
    local_24 = 0.0;
    *(undefined4 *)pdVar3 = *param_1;
    *(undefined4 *)((int)pdVar3 + 4) = param_1[1];
    *pdVar2 = *param_3 / *pdVar3;
    *pdVar1 = param_3[param_4 * (param_9 - 1)] / *pdVar3;
    for (local_28 = 1; local_28 < param_9 - 2; local_28 = local_28 + 1) {
      pdVar3[local_28] =
           *(double *)(param_1 + param_2 * local_28 * 2) -
           param_3[param_4 * (local_28 - 1)] * pdVar2[local_28 - 1];
      pdVar2[local_28] = param_3[param_4 * local_28] / pdVar3[local_28];
      pdVar1[local_28] =
           (-pdVar1[local_28 - 1] * param_3[param_4 * (local_28 - 1)]) / pdVar3[local_28];
    }
    for (local_28 = 0; local_28 < param_9 - 2; local_28 = local_28 + 1) {
      local_24 = pdVar3[local_28] * pdVar1[local_28] * pdVar1[local_28] + local_24;
    }
    pdVar3[param_9 - 2] =
         *(double *)(param_1 + param_2 * (param_9 - 2) * 2) -
         param_3[param_4 * (param_9 - 3)] * pdVar2[param_9 - 3];
    pdVar2[param_9 - 2] =
         (param_3[param_4 * (param_9 - 2)] - param_3[param_4 * (param_9 - 3)] * pdVar1[param_9 - 3])
         / pdVar3[param_9 - 2];
    pdVar3[param_9 - 1] =
         (*(double *)(param_1 + param_2 * (param_9 - 1) * 2) - local_24) -
         param_3[param_4 * (param_9 - 2)] * pdVar2[param_9 - 2] * pdVar2[param_9 - 2];
    *puVar5 = *param_5;
    puVar5[1] = param_5[1];
    for (local_28 = 1; local_28 < param_9 - 1; local_28 = local_28 + 1) {
      *(double *)(puVar5 + local_28 * 2) =
           *(double *)(param_5 + param_6 * local_28 * 2) -
           *(double *)(puVar5 + local_28 * 2 + -2) * pdVar2[local_28 - 1];
    }
    local_24 = 0.0;
    for (local_28 = 0; local_28 < param_9 - 2; local_28 = local_28 + 1) {
      local_24 = pdVar1[local_28] * *(double *)(puVar5 + local_28 * 2) + local_24;
    }
    *(double *)(puVar5 + param_9 * 2 + -2) =
         (*(double *)(param_5 + param_6 * (param_9 - 1) * 2) - local_24) -
         pdVar2[param_9 - 2] * *(double *)(puVar5 + param_9 * 2 + -4);
    for (local_28 = 0; local_28 < param_9; local_28 = local_28 + 1) {
      *(double *)((int)pvVar4 + local_28 * 8) =
           *(double *)(puVar5 + local_28 * 2) / pdVar3[local_28];
    }
    iVar6 = param_8 * (param_9 - 1);
    *(undefined4 *)(param_7 + iVar6 * 8) = *(undefined4 *)((int)pvVar4 + param_9 * 8 + -8);
    *(undefined4 *)(param_7 + 4 + iVar6 * 8) = *(undefined4 *)((int)pvVar4 + param_9 * 8 + -4);
    *(double *)(param_7 + param_8 * (param_9 - 2) * 8) =
         *(double *)((int)pvVar4 + param_9 * 8 + -0x10) -
         pdVar2[param_9 - 2] * *(double *)(param_7 + param_8 * (param_9 - 1) * 8);
    if (2 < param_9) {
      local_28 = param_9 - 3;
      for (local_2c = 0; local_2c <= param_9 - 3; local_2c = local_2c + 1) {
        *(double *)(param_7 + param_8 * local_28 * 8) =
             (*(double *)((int)pvVar4 + local_28 * 8) -
             pdVar2[local_28] * *(double *)(param_7 + param_8 * (local_28 + 1) * 8)) -
             pdVar1[local_28] * *(double *)(param_7 + param_8 * (param_9 - 1) * 8);
        local_28 = local_28 + -1;
      }
    }
    local_18 = 0;
  }
  if (puVar5 != (undefined4 *)0x0) {
    FUN_005089fd(puVar5);
  }
  if (pvVar4 != (void *)0x0) {
    FUN_005089fd(pvVar4);
  }
  if (pdVar3 != (double *)0x0) {
    FUN_005089fd(pdVar3);
  }
  if (pdVar2 != (double *)0x0) {
    FUN_005089fd(pdVar2);
  }
  if (pdVar1 != (double *)0x0) {
    FUN_005089fd(pdVar1);
  }
  return local_18;
}


