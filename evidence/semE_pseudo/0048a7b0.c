undefined4 __fastcall FUN_0048a7b0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x344))();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*param_1 + 0x364))();
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}


