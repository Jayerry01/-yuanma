void __fastcall FUN_00574080(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x2c) != 0) && (*(int *)(*(int *)(param_1 + 0x28) + 0x338) != 0)) {
    FUN_00475400(param_1 + 0x6c,param_1 + 0xe4,0);
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x34)) {
    do {
      FUN_00574080();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x34));
  }
  return;
}


