void __thiscall FUN_0057e590(int param_1,undefined4 param_2,int param_3)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  float *pfVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float local_140;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  undefined1 local_12c [12];
  undefined1 local_120 [64];
  undefined1 local_e0 [4];
  float local_dc [23];
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  iVar2 = FUN_0057e550(param_2,param_3);
  if (iVar2 != 0) {
    FUN_00477200();
    FUN_00477200();
    FUN_00478670(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 0x10),
                 *(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x18));
    FUN_00477b90(3,iVar2);
    uVar3 = FUN_00476f00(local_80,param_1 + 0xd8,local_120,param_3 + 0x54);
    puVar4 = (undefined4 *)FUN_00476f00(local_40,uVar3);
    puVar6 = puVar4;
    puVar7 = (undefined4 *)(param_1 + 0x118);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    puVar6 = (undefined4 *)(*(int *)(param_1 + 4) * 0x40 + *(int *)(param_3 + 0x154));
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    FUN_00476e80(local_12c,param_1 + 0x244,(undefined4 *)(param_1 + 0x118));
    puVar4 = (undefined4 *)(param_1 + 0x158);
    puVar6 = (undefined4 *)(param_1 + 0x118);
    puVar7 = puVar4;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    FUN_00477b90(3,local_12c);
    puVar6 = puVar4;
    puVar7 = (undefined4 *)(*(int *)(param_1 + 4) * 0x40 + *(int *)(param_3 + 0x158));
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    FUN_00475220(param_1 + 0x198,puVar4,local_e0);
    *(undefined4 *)(param_1 + 0x228) = 0x501502f9;
    *(undefined4 *)(param_1 + 0x224) = 0x501502f9;
    *(undefined4 *)(param_1 + 0x220) = 0x501502f9;
    *(undefined4 *)(param_1 + 0x234) = 0xd01502f9;
    *(undefined4 *)(param_1 + 0x230) = 0xd01502f9;
    *(undefined4 *)(param_1 + 0x22c) = 0xd01502f9;
    local_130 = *(float *)(param_1 + 0x220);
    local_134 = *(float *)(param_1 + 0x224);
    local_13c = *(float *)(param_1 + 0x228);
    fVar1 = *(float *)(param_1 + 0x234);
    local_138 = *(float *)(param_1 + 0x22c);
    local_140 = *(float *)(param_1 + 0x230);
    pfVar5 = local_dc;
    iVar2 = 8;
    do {
      if (pfVar5[-1] < local_130) {
        local_130 = pfVar5[-1];
      }
      if (*pfVar5 < local_134) {
        local_134 = *pfVar5;
      }
      if (pfVar5[1] < local_13c) {
        local_13c = pfVar5[1];
      }
      if (local_138 < pfVar5[-1]) {
        local_138 = pfVar5[-1];
      }
      if (local_140 < *pfVar5) {
        local_140 = *pfVar5;
      }
      if (fVar1 < pfVar5[1]) {
        fVar1 = pfVar5[1];
      }
      pfVar5 = pfVar5 + 3;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(float *)(param_1 + 0x220) = local_130;
    *(float *)(param_1 + 0x224) = local_134;
    *(float *)(param_1 + 0x228) = local_13c;
    *(float *)(param_1 + 0x234) = fVar1;
    *(float *)(param_1 + 0x22c) = local_138;
    *(float *)(param_1 + 0x230) = local_140;
  }
  return;
}


