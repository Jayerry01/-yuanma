void __fastcall FUN_0049ca90(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*param_1 != 0) {
    iVar1 = param_1[9];
    for (puVar2 = (undefined4 *)param_1[5]; puVar2 < (undefined4 *)(iVar1 + 4); puVar2 = puVar2 + 1)
    {
      FUN_00402e90(*puVar2,0x1f8);
    }
    if (param_1[1] != 0) {
      FUN_00402e90(*param_1,param_1[1] * 4);
    }
  }
  return;
}


