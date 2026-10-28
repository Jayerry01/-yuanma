FUN_0054e7c0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
            undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_5;
  if ((*(int *)(param_1 + 0x14) == 1) && (-1 < param_5)) {
    FUN_00553830();
    DAT_00724e24 = 0x7f;
    DAT_00724e25 = 4;
    FUN_0054f670(&DAT_00724e20,param_6);
    param_5 = param_3;
    FUN_005538e0(&param_5,2);
    FUN_005538e0(param_4,iVar3);
    iVar3 = *(int *)(*(int *)(param_1 + 4) + 8);
    if (iVar3 != *(int *)(param_1 + 4)) {
      do {
        if (*(int *)(*(int *)(iVar3 + 0x14) + 0x10) != param_2) {
          FUN_0054f760(&DAT_00724e20);
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
          for (iVar1 = *(int *)(iVar2 + 8); iVar3 = iVar2, iVar1 != 0; iVar1 = *(int *)(iVar1 + 8))
          {
            iVar2 = iVar1;
          }
        }
      } while (iVar3 != *(int *)(param_1 + 4));
    }
  }
  return;
}


