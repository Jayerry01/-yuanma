void FUN_00545ed0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar1 = *(int *)(param_1 + 0x5c);
  if (0 < *(int *)(param_1 + 100)) {
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x1a8) + 0x44);
    do {
      uVar2 = (**(code **)(*(int *)(param_1 + 4) + 4))(param_1,1,iVar1 * 2 + 4);
      *puVar3 = uVar2;
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar4 < *(int *)(param_1 + 100));
  }
  return;
}


