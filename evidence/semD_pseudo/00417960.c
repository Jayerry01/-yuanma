void FUN_00417960(undefined4 *param_1,float *param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float local_c;
  float local_8;
  float local_4;
  
  iVar7 = param_1[2];
  FUN_0040fb30(*(uint *)param_1[3] | 0x5000000,&local_c,0);
  iVar1 = param_1[4];
  iVar5 = 0;
  fVar2 = local_c * *param_2 + local_8 * param_2[4] + local_4 * param_2[8] + param_2[0xc];
  fVar4 = local_c * param_2[1] + local_8 * param_2[5] + local_4 * param_2[9] + param_2[0xd];
  fVar3 = local_c * param_2[2] + local_8 * param_2[6] + local_4 * param_2[10] + param_2[0xe];
  iVar6 = iVar7;
  if (0 < iVar1) {
    do {
      if (*(float *)(param_1[5] + iVar5 * 4) < fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3) {
        iVar6 = *(int *)(param_1[6] + iVar5 * 4);
        break;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  if (iVar6 != 0) {
    FUN_0040fae0(iVar7,0);
    iVar7 = 0;
    if (0 < iVar1) {
      do {
        iVar5 = *(int *)(param_1[6] + iVar7 * 4);
        if (iVar5 != 0) {
          FUN_0040fae0(iVar5,0);
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar1);
    }
    param_1[3] = iVar6;
    FUN_0040fae0(iVar6,*param_1);
  }
  return;
}


