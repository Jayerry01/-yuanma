void __fastcall FUN_00588010(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  FUN_005824f0();
  if (*(int *)(param_1 + 0x2e8) != 0) {
    puVar2 = (undefined4 *)(param_1 + 0x58);
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x2e8) + 0x54);
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


