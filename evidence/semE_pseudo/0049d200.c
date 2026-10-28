void FUN_0049d200(int param_1)

{
  int iVar1;
  
  while (param_1 != 0) {
    FUN_0049d200(*(undefined4 *)(param_1 + 0xc));
    iVar1 = *(int *)(param_1 + 8);
    FUN_0048f050();
    FUN_00402e90(param_1,0x2b8);
    param_1 = iVar1;
  }
  return;
}


