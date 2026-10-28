void __fastcall FUN_004953f0(int *param_1)

{
  int iVar1;
  int iVar2;
  void **ppvVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0059eab8;
  local_c = ExceptionList;
  local_4 = 0;
  ppvVar3 = &local_c;
  if (param_1[1] != 0) {
    iVar2 = *(int *)(*param_1 + 4);
    ExceptionList = &local_c;
    while (iVar2 != 0) {
      FUN_0049d200(*(undefined4 *)(iVar2 + 0xc));
      iVar1 = *(int *)(iVar2 + 8);
      FUN_0049fc60(0);
      FUN_00402e90(iVar2,0x2b8);
      iVar2 = iVar1;
    }
    *(int *)(*param_1 + 8) = *param_1;
    *(undefined4 *)(*param_1 + 4) = 0;
    *(int *)(*param_1 + 0xc) = *param_1;
    param_1[1] = 0;
    ppvVar3 = ExceptionList;
  }
  ExceptionList = ppvVar3;
  FUN_005089fd(*param_1);
  ExceptionList = local_c;
  return;
}


