void __fastcall FUN_0058f6c0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 3;
  piVar2 = (int *)(param_1 + 0x8c);
  do {
    if (piVar2[3] != 0) {
      FUN_00595909(piVar2[3]);
      piVar2[3] = 0;
    }
    if (*piVar2 != 0) {
      FUN_00595346(*piVar2);
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (*(int *)(param_1 + 0xa4) != 0) {
    FUN_00507850(*(int *)(param_1 + 0xa4));
    *(undefined4 *)(param_1 + 0xa4) = 0;
  }
  if (*(int *)(param_1 + 0xa8) != 0) {
    FUN_00507850(*(int *)(param_1 + 0xa8));
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
  if (*(int *)(param_1 + 0xac) != 0) {
    FUN_00507850(*(int *)(param_1 + 0xac));
    *(undefined4 *)(param_1 + 0xac) = 0;
  }
  if (*(int *)(param_1 + 0xb0) != 0) {
    FUN_00507850(*(int *)(param_1 + 0xb0));
    *(undefined4 *)(param_1 + 0xb0) = 0;
  }
  return;
}


