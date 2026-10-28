void __thiscall FUN_00571500(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)param_1[7];
  if (puVar1 != (undefined4 *)param_1[8]) {
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = param_2;
    }
    iVar2 = param_1[7];
    param_1[7] = iVar2 + 4;
    *param_1 = (iVar2 + 4) - param_1[6] >> 2;
    return;
  }
  FUN_005719b0(puVar1,&param_2);
  *param_1 = param_1[7] - param_1[6] >> 2;
  return;
}


