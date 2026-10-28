undefined4 FUN_00542050(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar1 = *(int *)(param_1 + 0x198);
  *(int *)(*(int *)(param_1 + 0x194) + 0x14) =
       *(int *)(*(int *)(param_1 + 0x194) + 0x14) +
       ((int)(*(int *)(iVar1 + 0x10) + (*(int *)(iVar1 + 0x10) >> 0x1f & 7U)) >> 3);
  *(undefined4 *)(iVar1 + 0x10) = 0;
  uVar2 = (**(code **)(*(int *)(param_1 + 0x194) + 8))(param_1);
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x124)) {
    puVar4 = (undefined4 *)(iVar1 + 0x14);
    do {
      *puVar4 = 0;
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x124));
  }
  *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(param_1 + 0xfc);
  iVar3 = *(int *)(param_1 + 0x17c);
  if (iVar3 == 0) {
    *(undefined1 *)(iVar1 + 8) = 0;
  }
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


