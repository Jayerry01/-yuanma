void __fastcall FUN_00561120(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  FUN_0056d2e0();
  if (*(int *)(param_1 + 0x288) != 0) {
    FUN_00507850(*(int *)(param_1 + 0x288));
    *(undefined4 *)(param_1 + 0x288) = 0;
  }
  iVar1 = FUN_0056b210();
  pvVar2 = operator_new(iVar1 * 0x30);
  if (pvVar2 != (void *)0x0) {
    if (-1 < iVar1 + -1) {
      puVar3 = (undefined4 *)((int)pvVar2 + 0xc);
      do {
        puVar3[-3] = 0xffffffff;
        puVar3[-2] = 0xffffffff;
        *puVar3 = 0;
        puVar3[-1] = 0;
        puVar3[2] = 0xffffffff;
        puVar3[3] = 0xffffffff;
        puVar3[4] = 0xffffffff;
        puVar3[5] = 0;
        puVar3[6] = 0;
        puVar3[7] = 0;
        puVar3 = puVar3 + 0xc;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    *(void **)(param_1 + 0x288) = pvVar2;
    return;
  }
  *(undefined4 *)(param_1 + 0x288) = 0;
  return;
}


