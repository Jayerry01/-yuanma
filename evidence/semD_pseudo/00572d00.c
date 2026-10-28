void __thiscall FUN_00572d00(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  *(int *)(param_1 + 0xa8) = param_2;
  if (param_2 != 0) {
    if (*(int *)(param_1 + 0xb8) == 0) {
      FUN_0047da70(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x60),0x40a00000,0x40a00000);
    }
    if (*(int *)(param_1 + 0x1b4) == 0) {
      puVar3 = (undefined4 *)(param_1 + 0x1a8);
      iVar4 = 3;
      do {
        uVar1 = FUN_00595890();
        puVar3[3] = uVar1;
        uVar1 = FUN_005951e0(PTR_PTR_005d3bb0,5);
        *puVar3 = uVar1;
        uVar1 = FUN_00595890();
        puVar3[9] = uVar1;
        uVar1 = FUN_005951e0(PTR_PTR_005d3bb0,5);
        puVar3[6] = uVar1;
        puVar3 = puVar3 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    puVar2 = (undefined4 *)FUN_0047b740();
    puVar3 = (undefined4 *)(param_1 + 0x3c);
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar2 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar2 = puVar2 + 1;
    }
    FUN_0047b750();
  }
  return;
}


