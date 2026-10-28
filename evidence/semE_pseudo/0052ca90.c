undefined4 FUN_0052ca90(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    if (*(int *)(param_1 + 0x14) == 0) {
      iVar1 = FUN_00530d80(*(undefined4 *)(param_1 + 0x18));
      *(int *)(param_1 + 0x14) = iVar1;
      if (iVar1 == 0) {
        return 0;
      }
    }
    uVar3 = *(uint *)(param_1 + 0x18);
    puVar4 = *(undefined4 **)(param_1 + 0x14);
    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = *param_2;
      param_2 = param_2 + 1;
      puVar4 = puVar4 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    return 1;
  }
  FUN_00530d00(0x509);
  return 0;
}


