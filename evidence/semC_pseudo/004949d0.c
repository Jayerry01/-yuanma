undefined4 __thiscall FUN_004949d0(int *param_1,int param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  float *pfVar9;
  float *pfVar10;
  bool bVar11;
  uint local_110;
  undefined1 auStack_108 [4];
  float local_104 [4];
  undefined4 local_f4;
  undefined4 local_f0;
  undefined1 auStack_a4 [36];
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  uint auStack_74 [2];
  float afStack_6c [24];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0059e9de;
  local_c = ExceptionList;
  local_110 = param_3 / 0x18;
  if (local_110 != 0) {
    piVar1 = param_1 + 0x8be;
    puVar7 = (undefined4 *)(param_2 + 8);
    ExceptionList = &local_c;
    do {
      FUN_005498c0();
      uVar2 = puVar7[-2];
      local_104[3] = (float)puVar7[-1];
      local_104[0] = (float)(int)puVar7[1] * 0.1;
      local_f4 = *puVar7;
      local_f0 = 0;
      local_104[1] = (float)(int)puVar7[2] * 0.1;
      local_104[2] = (float)(int)puVar7[3] * 0.1;
      iVar4 = (**(code **)(*param_1 + 0x148))(local_f4,local_104[3]);
      uVar8 = 0;
      if (iVar4 != 0) {
        pvVar5 = operator_new(0x1d0);
        uStack_4 = 0;
        if (pvVar5 != (void *)0x0) {
          uVar8 = FUN_005678a0();
        }
        uStack_4 = 0xffffffff;
        FUN_0056b230(uVar8);
        FUN_0047b310(uVar8);
        FUN_0047b740();
        FUN_00477eb0(auStack_a4);
        fStack_80 = local_104[0];
        fStack_7c = local_104[1];
        fStack_78 = local_104[2];
        FUN_00477e30(auStack_a4);
      }
      local_f0 = uVar8;
      auStack_74[0] = uVar2;
      pfVar9 = local_104;
      pfVar10 = afStack_6c;
      for (iVar4 = 0x18; iVar4 != 0; iVar4 = iVar4 + -1) {
        *pfVar10 = *pfVar9;
        pfVar9 = pfVar9 + 1;
        pfVar10 = pfVar10 + 1;
      }
      iVar4 = *piVar1;
      puVar7 = puVar7 + 6;
      bVar11 = true;
      iVar3 = iVar4;
      iVar6 = *(int *)(iVar4 + 4);
      while (iVar6 != 0) {
        bVar11 = uVar2 < *(uint *)(iVar6 + 0x10);
        iVar3 = iVar6;
        if (bVar11) {
          iVar6 = *(int *)(iVar6 + 8);
        }
        else {
          iVar6 = *(int *)(iVar6 + 0xc);
        }
      }
      if (bVar11) {
        if (iVar3 != *(int *)(iVar4 + 8)) {
          FUN_0044cf00();
          goto LAB_00494c03;
        }
        if ((iVar3 == iVar4) || (uVar2 < *(uint *)(iVar3 + 0x10))) {
          iVar6 = FUN_0049f670(auStack_74);
          *(int *)(iVar3 + 8) = iVar6;
          iVar4 = *piVar1;
          if (iVar3 == iVar4) {
            *(int *)(iVar4 + 4) = iVar6;
            *(int *)(*piVar1 + 0xc) = iVar6;
          }
          else if (iVar3 == *(int *)(iVar4 + 8)) {
            *(int *)(iVar4 + 8) = iVar6;
          }
        }
        else {
          iVar6 = FUN_0049f670(auStack_74);
          *(int *)(iVar3 + 0xc) = iVar6;
          if (iVar3 == *(int *)(*piVar1 + 0xc)) {
            *(int *)(*piVar1 + 0xc) = iVar6;
          }
        }
        *(int *)(iVar6 + 4) = iVar3;
        *(undefined4 *)(iVar6 + 8) = 0;
        *(undefined4 *)(iVar6 + 0xc) = 0;
        FUN_00460be0(iVar6,*piVar1 + 4);
        param_1[0x8bf] = param_1[0x8bf] + 1;
      }
      else {
LAB_00494c03:
        if (*(uint *)(iVar3 + 0x10) < uVar2) {
          FUN_0049ebb0(auStack_108,0,iVar3,auStack_74);
        }
      }
      local_110 = local_110 - 1;
    } while (local_110 != 0);
  }
  ExceptionList = local_c;
  return 1;
}


