void FUN_00417850(int param_1,float *param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float *pfVar8;
  uint *puVar9;
  float local_c;
  float local_8;
  float local_4;
  
  puVar1 = *(uint **)(param_1 + 4);
  FUN_00407c10(*puVar1 | 0x2000000,&local_c,0,0);
  iVar7 = 0;
  fVar4 = local_c * *param_2 + local_8 * param_2[4] + local_4 * param_2[8] + param_2[0xc];
  fVar6 = local_c * param_2[1] + local_8 * param_2[5] + local_4 * param_2[9] + param_2[0xd];
  fVar5 = local_c * param_2[2] + local_8 * param_2[6] + local_4 * param_2[10] + param_2[0xe];
  puVar9 = puVar1;
  if (0 < *(int *)(param_1 + 0xc)) {
    pfVar8 = *(float **)(param_1 + 0x10);
    do {
      if (*pfVar8 < fVar4 * fVar4 + fVar6 * fVar6 + fVar5 * fVar5) {
        puVar9 = *(uint **)(*(int *)(param_1 + 0x14) + iVar7 * 4);
        break;
      }
      iVar7 = iVar7 + 1;
      pfVar8 = pfVar8 + 1;
    } while (iVar7 < *(int *)(param_1 + 0xc));
  }
  if (puVar9 != (uint *)0x0) {
    iVar7 = 0;
    uVar2 = *(uint *)(*(int *)(param_1 + 8) + 0x8c);
    puVar1[0x23] = 0;
    if (0 < *(int *)(param_1 + 0xc)) {
      do {
        iVar3 = *(int *)(*(int *)(param_1 + 0x14) + iVar7 * 4);
        if (iVar3 != 0) {
          *(undefined4 *)(iVar3 + 0x8c) = 0;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < *(int *)(param_1 + 0xc));
    }
    *(uint **)(param_1 + 8) = puVar9;
    puVar9[0x23] = uVar2;
  }
  return;
}


