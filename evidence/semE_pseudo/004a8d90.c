void FUN_004a8d90(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = param_3;
  for (puVar1 = param_2; puVar1 != puVar2; puVar1 = (undefined4 *)*puVar1) {
    FUN_0049a680(&param_1);
    puVar3 = (undefined4 *)FUN_004a8e90(puVar1 + 2);
    *puVar3 = param_2;
    puVar3[1] = param_2[1];
    *(undefined4 **)param_2[1] = puVar3;
    param_2[1] = puVar3;
  }
  return;
}


