void __thiscall FUN_00570fe0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x38);
  if (puVar1 != *(undefined4 **)(param_1 + 0x3c)) {
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = param_2;
    }
    iVar2 = *(int *)(param_1 + 0x38) + 4;
    *(int *)(param_1 + 0x38) = iVar2;
    *(int *)(param_1 + 0x30) = iVar2 - *(int *)(param_1 + 0x34) >> 2;
    return;
  }
  FUN_005716f0(puVar1,&param_2);
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x38) - *(int *)(param_1 + 0x34) >> 2;
  return;
}


