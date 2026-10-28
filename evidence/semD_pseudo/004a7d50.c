undefined4 __thiscall FUN_004a7d50(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  pvVar2 = operator_new((*(int *)(param_1 + 0x42c) + *(int *)(param_1 + 0x434)) * 4);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x42c)) {
    iVar5 = 0;
    do {
      iVar3 = iVar3 + 1;
      puVar1 = (undefined4 *)(*(int *)(param_1 + 0x404) + 0x10 + iVar5);
      iVar5 = iVar5 + 0x2c;
      *(undefined4 *)((int)pvVar2 + iVar3 * 4 + -4) = *puVar1;
    } while (iVar3 < *(int *)(param_1 + 0x42c));
  }
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x434)) {
    iVar5 = 0;
    do {
      iVar6 = *(int *)(param_1 + 0x42c) + iVar3;
      iVar3 = iVar3 + 1;
      puVar1 = (undefined4 *)(*(int *)(param_1 + 0x40c) + 0x10 + iVar5);
      iVar5 = iVar5 + 0x2c;
      *(undefined4 *)((int)pvVar2 + iVar6 * 4) = *puVar1;
    } while (iVar3 < *(int *)(param_1 + 0x434));
  }
  uVar4 = thunk_FUN_0040db40(0,pvVar2,*(int *)(param_1 + 0x42c) + *(int *)(param_1 + 0x434),1,
                             param_2,param_3,0,0,0,0);
  FUN_00507850(pvVar2);
  return uVar4;
}


