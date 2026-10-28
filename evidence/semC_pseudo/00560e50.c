void __fastcall FUN_00560e50(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (*(int **)(param_1 + 0x6c8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x6c8) + 4))();
  }
  FUN_0056cef0();
  if (*(int *)(param_1 + 0x2e4) != 0) {
    FUN_00507850(*(int *)(param_1 + 0x2e4));
    *(undefined4 *)(param_1 + 0x2e4) = 0;
  }
  if (*(int *)(param_1 + 0x2e8) != 0) {
    FUN_00507850(*(int *)(param_1 + 0x2e8));
    *(undefined4 *)(param_1 + 0x2e8) = 0;
  }
  iVar2 = *(int *)(param_1 + 0x2ec);
  if (iVar2 != 0) {
    FUN_0050ace3(iVar2,0x58,*(undefined4 *)(iVar2 + -4),&LAB_00560fc0);
    FUN_00507850(iVar2 + -4);
    *(undefined4 *)(param_1 + 0x2ec) = 0;
  }
  if (*(int *)(param_1 + 0x2f0) != 0) {
    FUN_00507850(*(int *)(param_1 + 0x2f0));
    *(undefined4 *)(param_1 + 0x2f0) = 0;
  }
  if (*(int *)(param_1 + 0x288) != 0) {
    FUN_00507850(*(int *)(param_1 + 0x288));
    *(undefined4 *)(param_1 + 0x288) = 0;
  }
  if (*(int *)(param_1 + 0x2fc) != 0) {
    FUN_00507850(*(int *)(param_1 + 0x2fc));
    *(undefined4 *)(param_1 + 0x2fc) = 0;
  }
  if (*(int *)(param_1 + 0x2f8) != 0) {
    FUN_00507850(*(int *)(param_1 + 0x2f8));
    *(undefined4 *)(param_1 + 0x2f8) = 0;
  }
  if ((*(char *)(param_1 + 0x256) == '\0') && (*(int *)(param_1 + 0x2f4) != 0)) {
    FUN_00507850(*(int *)(param_1 + 0x2f4));
    *(undefined4 *)(param_1 + 0x2f4) = 0;
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x4b0)) {
    iVar3 = 0;
    do {
      piVar1 = *(int **)(iVar3 + 0x2c + *(int *)(param_1 + 0x4b4));
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(1);
        *(undefined4 *)(iVar3 + 0x2c + *(int *)(param_1 + 0x4b4)) = 0;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xac;
    } while (iVar2 < *(int *)(param_1 + 0x4b0));
  }
  if (*(int *)(param_1 + 0x4b4) != 0) {
    FUN_00507850(*(int *)(param_1 + 0x4b4));
    *(undefined4 *)(param_1 + 0x4b4) = 0;
  }
  *(undefined4 *)(param_1 + 0x4b0) = 0;
  *(undefined4 *)(param_1 + 0x4b8) = 0;
  *(undefined1 *)(param_1 + 0x25a) = 0;
  return;
}


