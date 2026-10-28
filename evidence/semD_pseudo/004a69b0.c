undefined4 __thiscall FUN_004a69b0(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x464)) {
    iVar4 = 0;
    do {
      puVar1 = (undefined4 *)(*(int *)(param_1 + 0x43c) + 0x10 + iVar4);
      puVar2 = *(undefined4 **)(param_2 + 4);
      if (puVar2 == *(undefined4 **)(param_2 + 8)) {
        FUN_0049c640(puVar2,puVar1);
      }
      else {
        if (puVar2 != (undefined4 *)0x0) {
          *puVar2 = *puVar1;
        }
        *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 4;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x2c;
    } while (iVar3 < *(int *)(param_1 + 0x464));
  }
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x45c)) {
    iVar4 = 0;
    do {
      if ((param_3 == 0) || (-1 < *(char *)(*(int *)(param_1 + 0x434) + 0x24 + iVar4))) {
        puVar1 = (undefined4 *)(*(int *)(param_1 + 0x434) + 0x10 + iVar4);
        puVar2 = *(undefined4 **)(param_2 + 4);
        if (puVar2 == *(undefined4 **)(param_2 + 8)) {
          FUN_0049c640(puVar2,puVar1);
        }
        else {
          if (puVar2 != (undefined4 *)0x0) {
            *puVar2 = *puVar1;
          }
          *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + 4;
        }
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x2c;
    } while (iVar3 < *(int *)(param_1 + 0x45c));
  }
  return 1;
}


