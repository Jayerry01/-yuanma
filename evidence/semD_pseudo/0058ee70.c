void __fastcall FUN_0058ee70(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int *piStack_4;
  
  piStack_4 = param_1;
  if (param_1[4] == *(int *)(*(int *)(param_1[2] + 0x1ec) + 0xe4) + -1) {
    iVar2 = 0;
    if (0 < param_1[4]) {
      do {
        (**(code **)(**(int **)(param_1[0x20] + iVar2 * 4) + 4))();
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[4]);
    }
  }
  else {
    (**(code **)(*param_1 + 0x18))();
    iVar4 = 0;
    iVar2 = *(int *)(*(int *)(param_1[2] + 0x1ec) + 0xe4) + -1;
    param_1[4] = iVar2;
    if (0 < iVar2) {
      do {
        pvVar3 = operator_new(0x58);
        if (pvVar3 == (void *)0x0) {
          piStack_4 = (int *)0x0;
        }
        else {
          piStack_4 = (int *)FUN_0058ea20(iVar4,param_1);
        }
        (**(code **)(*piStack_4 + 4))();
        puVar1 = (undefined4 *)param_1[0x21];
        if (puVar1 == (undefined4 *)param_1[0x22]) {
          FUN_0058f330(puVar1,&piStack_4);
        }
        else {
          if (puVar1 != (undefined4 *)0x0) {
            *puVar1 = piStack_4;
          }
          param_1[0x21] = param_1[0x21] + 4;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_1[4]);
      return;
    }
  }
  return;
}


