void __fastcall FUN_005870d0(int param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x28c) == 0) {
    iVar3 = *(int *)(param_1 + 0x26c);
    pvVar1 = operator_new(iVar3 * 0xac);
    if (pvVar1 == (void *)0x0) {
      pvVar1 = (void *)0x0;
    }
    else if (-1 < iVar3 + -1) {
      do {
        FUN_005858e0();
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    *(void **)(param_1 + 0x28c) = pvVar1;
  }
  piVar2 = *(int **)(param_1 + 0x28c);
  iVar3 = 0;
  *(int *)(param_1 + 0x268) = *(int *)(param_1 + 0x26c);
  if (0 < *(int *)(param_1 + 0x26c)) {
    do {
      *piVar2 = iVar3;
      FUN_00586d40(piVar2);
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 0x2b;
    } while (iVar3 < *(int *)(param_1 + 0x26c));
  }
  return;
}


