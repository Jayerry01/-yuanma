FUN_0047dcf0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_00475c50(param_2,param_3,param_4,param_5);
  FUN_00481b30();
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      FUN_00481d00(iVar2,uVar1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 4));
  }
  FUN_00481b90();
  return;
}



void __thiscall