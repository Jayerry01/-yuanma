undefined4 FUN_00557ab0(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  undefined1 local_4c [64];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar2 = (int)param_2;
  uVar4 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a4fbb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_005572d0(param_1,param_2);
  piVar1 = (int *)((int)param_2 + 0x30);
  FUN_0050b600(param_1,s__s__d_005d1280,local_4c,piVar1);
  iVar7 = *piVar1;
  piVar3 = operator_new(iVar7 * 4 + 4);
  local_4 = 0;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    *piVar3 = iVar7;
    piVar3 = piVar3 + 1;
    FUN_0050ac61(piVar3,4,iVar7,&LAB_00571d30,FUN_0057d910);
  }
  local_4 = 0xffffffff;
  *(int **)((int)param_2 + 0x34) = piVar3;
  if (piVar3 == (int *)0x0) {
LAB_00557b48:
    uVar4 = 0;
  }
  else {
    param_1 = 0;
    param_2 = piVar3;
    if (0 < *piVar1) {
      do {
        pvVar5 = operator_new(*(int *)(iVar2 + 0x10) * 0xc);
        *param_2 = (int)pvVar5;
        if (pvVar5 == (void *)0x0) goto LAB_00557b48;
        FUN_00571c70(uVar4,2);
        iVar7 = 0;
        if (0 < *(int *)(iVar2 + 0x10)) {
          iVar6 = (int)pvVar5 + 4;
          do {
            FUN_0050b600(uVar4,s__s__f__f__f_005d1298,local_4c,iVar6 + -4,iVar6,iVar6 + 4);
            iVar7 = iVar7 + 1;
            iVar6 = iVar6 + 0xc;
          } while (iVar7 < *(int *)(iVar2 + 0x10));
        }
        FUN_00571c70(uVar4,1);
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
      } while (param_1 < *(int *)(iVar2 + 0x30));
    }
    uVar4 = 1;
  }
  ExceptionList = local_c;
  return uVar4;
}


