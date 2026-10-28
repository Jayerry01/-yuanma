void FUN_0054ea00(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = FUN_0054f530(param_1);
  if (iVar2 != 0) {
    FUN_00553830();
    uVar1 = param_2;
    DAT_00724e24 = 4;
    param_1 = param_2;
    FUN_005538e0(&param_1,4);
    FUN_0054f2d0(&DAT_00724e20,iVar2);
    *(undefined4 *)(iVar2 + 0xa0) = uVar1;
    *(undefined1 *)(iVar2 + 0x9c) = 1;
  }
  return;
}


