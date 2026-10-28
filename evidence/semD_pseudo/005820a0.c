void __fastcall FUN_005820a0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*(char *)(param_1 + 0x38) != '\0') {
    FUN_0047c1c0();
    FUN_0058e730();
    iVar1 = *(int *)(*(int *)(param_1 + 0x1ec) + 0x1fc);
    if (iVar1 != 0) {
      FUN_00507850(iVar1);
      *(undefined4 *)(*(int *)(param_1 + 0x1ec) + 0x1fc) = 0;
    }
    piVar2 = *(int **)(*(int *)(param_1 + 0x1ec) + 0x10);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x14))(1);
      *(undefined4 *)(*(int *)(param_1 + 0x1ec) + 0x10) = 0;
    }
  }
  return;
}


