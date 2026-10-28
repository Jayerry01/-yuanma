undefined1 * FUN_00403870(undefined1 *param_1,int param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  
  param_2 = param_2 - (int)param_1;
  if (param_2 < 1) {
    return param_3;
  }
  do {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_3 = uVar1;
    param_3 = param_3 + 1;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  return param_3;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
