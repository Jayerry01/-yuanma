void __thiscall FUN_004666a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x20) + 8);
  if (iVar3 != *(int *)(param_1 + 0x20)) {
    do {
      if (*(int *)(iVar3 + 0x14) != 0) {
        FUN_00466d30(param_2,param_3,param_4);
      }
      iVar2 = *(int *)(iVar3 + 0xc);
      if (iVar2 == 0) {
        iVar2 = *(int *)(iVar3 + 4);
        if (iVar3 == *(int *)(iVar2 + 0xc)) {
          do {
            iVar3 = iVar2;
            iVar2 = *(int *)(iVar3 + 4);
          } while (iVar3 == *(int *)(iVar2 + 0xc));
        }
        if (*(int *)(iVar3 + 0xc) != iVar2) {
          iVar3 = iVar2;
        }
      }
      else {
        for (iVar1 = *(int *)(iVar2 + 8); iVar3 = iVar2, iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
          iVar2 = iVar1;
        }
      }
    } while (iVar3 != *(int *)(param_1 + 0x20));
  }
  return;
}



undefined4 __thiscall