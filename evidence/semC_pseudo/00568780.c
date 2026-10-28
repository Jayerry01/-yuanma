undefined4 __thiscall FUN_00568780(int param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  void *pvVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_005a5936;
  pvStack_c = ExceptionList;
  iVar10 = *(int *)(param_1 + 0x120);
  ExceptionList = &pvStack_c;
  *(int *)(iVar10 + 0x34) = *(int *)(iVar10 + 0x40) + *(int *)(iVar10 + 0x38);
  if ((param_2 == 0) && (*(int *)(*(int *)(param_1 + 0x120) + 0x38) != 0)) {
    puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x120) + 0x3c);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(3);
      *(undefined4 *)(*(int *)(param_1 + 0x120) + 0x3c) = 0;
    }
    iVar10 = *(int *)(*(int *)(param_1 + 0x120) + 0x38);
    piVar3 = operator_new(iVar10 * 0x2b0 + 4);
    uStack_4 = 0;
    if (piVar3 == (int *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      piVar9 = piVar3 + 1;
      *piVar3 = iVar10;
      FUN_0050ac61(piVar9,0x2b0,iVar10,FUN_0057e3a0,FUN_0057e4a0);
    }
    *(int **)(*(int *)(param_1 + 0x120) + 0x3c) = piVar9;
    if (piVar9 != (int *)0x0) {
      iVar10 = 0;
      if (0 < *(int *)(*(int *)(param_1 + 0x120) + 0x38)) {
        iVar8 = 0;
        piVar9 = piVar9 + 1;
        do {
          *piVar9 = iVar10;
          pcVar6 = s_normal_005d1568;
          pcVar7 = (char *)(*(int *)(*(int *)(param_1 + 0x120) + 0x3c) + 0x88 + iVar8);
          do {
            cVar1 = *pcVar6;
            pcVar6 = pcVar6 + 1;
            *pcVar7 = cVar1;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          iVar10 = iVar10 + 1;
          iVar8 = iVar8 + 0x2b0;
          piVar9 = piVar9 + 0xac;
        } while (iVar10 < *(int *)(*(int *)(param_1 + 0x120) + 0x38));
      }
      goto LAB_0056889a;
    }
LAB_00568931:
    uStack_4 = 0xffffffff;
    FUN_005679f0();
    uVar4 = 0;
  }
  else {
LAB_0056889a:
    uStack_4 = 0xffffffff;
    iVar10 = 0;
    if (*(int *)(*(int *)(param_1 + 0x120) + 0x40) != 0) {
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x120) + 0x44);
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(3);
        *(undefined4 *)(*(int *)(param_1 + 0x120) + 0x44) = 0;
      }
      iVar8 = *(int *)(*(int *)(param_1 + 0x120) + 0x40);
      piVar3 = operator_new(iVar8 * 0x2b0 + 4);
      uStack_4 = 1;
      if (piVar3 == (int *)0x0) {
        piVar9 = (int *)0x0;
      }
      else {
        piVar9 = piVar3 + 1;
        *piVar3 = iVar8;
        FUN_0050ac61(piVar9,0x2b0,iVar8,FUN_0057e3a0,FUN_0057e4a0);
      }
      *(int **)(*(int *)(param_1 + 0x120) + 0x44) = piVar9;
      iVar8 = *(int *)(param_1 + 0x120);
      if (*(int *)(iVar8 + 0x44) == 0) goto LAB_00568931;
      iVar11 = 0;
      if (0 < *(int *)(iVar8 + 0x40)) {
        piVar9 = piVar9 + 1;
        do {
          pcVar6 = &DAT_005d1720;
          *piVar9 = *(int *)(iVar8 + 0x38) + iVar11;
          pcVar7 = (char *)(*(int *)(*(int *)(param_1 + 0x120) + 0x44) + 0x88 + iVar10);
          do {
            cVar1 = *pcVar6;
            pcVar6 = pcVar6 + 1;
            *pcVar7 = cVar1;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          iVar8 = *(int *)(param_1 + 0x120);
          iVar11 = iVar11 + 1;
          iVar10 = iVar10 + 0x2b0;
          piVar9 = piVar9 + 0xac;
        } while (iVar11 < *(int *)(iVar8 + 0x40));
      }
    }
    uStack_4 = 0xffffffff;
    if (*(int *)(param_1 + 0x154) != 0) {
      FUN_00507850(*(int *)(param_1 + 0x154));
      *(undefined4 *)(param_1 + 0x154) = 0;
    }
    if (*(int *)(param_1 + 0x158) != 0) {
      FUN_00507850(*(int *)(param_1 + 0x158));
      *(undefined4 *)(param_1 + 0x158) = 0;
    }
    pvVar5 = operator_new(*(int *)(*(int *)(param_1 + 0x120) + 0x34) << 6);
    *(void **)(param_1 + 0x154) = pvVar5;
    pvVar5 = operator_new(*(int *)(*(int *)(param_1 + 0x120) + 0x34) << 6);
    *(void **)(param_1 + 0x158) = pvVar5;
    iVar10 = 0;
    if (0 < *(int *)(*(int *)(param_1 + 0x120) + 0x34)) {
      do {
        FUN_00477200();
        FUN_00477200();
        iVar10 = iVar10 + 1;
      } while (iVar10 < *(int *)(*(int *)(param_1 + 0x120) + 0x34));
    }
    uVar4 = 1;
  }
  ExceptionList = pvStack_c;
  return uVar4;
}


