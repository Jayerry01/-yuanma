undefined4 __thiscall FUN_00561dc0(int param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 *puVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  undefined4 *puVar9;
  float local_70;
  float local_6c;
  float local_68;
  undefined1 local_64 [36];
  undefined4 local_40 [14];
  float local_8;
  
  FUN_00475f90(param_2);
  puVar5 = (undefined4 *)FUN_00476070(1);
  puVar9 = local_40;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar9 = puVar9 + 1;
  }
  FUN_00477b30(2,&local_70);
  FUN_00477d30(3,local_64);
  iVar6 = FUN_00561f00(local_64);
  if (iVar6 != 0) {
    if (*(int *)(param_1 + 0x278) == 0) {
      return 0;
    }
    iVar6 = 0;
    if (0 < *(int *)(param_1 + 0x284)) {
      pfVar7 = (float *)((*(int *)(param_1 + 0x278) - *(int *)(param_1 + 0x284)) * 0x30 +
                         *(int *)(param_1 + 0x288) + 0x2c);
      do {
        fVar1 = pfVar7[-8];
        fVar2 = *(float *)((int)fVar1 + 0x220);
        fVar3 = *(float *)((int)fVar1 + 0x224);
        iVar8 = 2;
        fVar1 = *(float *)((int)fVar1 + 0x228);
        *pfVar7 = 0.0;
        do {
          fVar4 = fVar2 * local_70 + fVar3 * local_6c + fVar1 * local_68 + local_8;
          if (*pfVar7 < fVar4) {
            *pfVar7 = fVar4;
          }
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        iVar6 = iVar6 + 1;
        pfVar7 = pfVar7 + 0xc;
      } while (iVar6 < *(int *)(param_1 + 0x284));
    }
  }
  return 1;
}


