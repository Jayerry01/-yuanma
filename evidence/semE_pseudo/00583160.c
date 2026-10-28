void FUN_00583160(int *param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)*param_1;
  while( true ) {
    if (puVar1 == (undefined4 *)*param_1) {
      FUN_004db820(&param_1);
      puVar1 = (undefined4 *)FUN_00583570(&param_2);
      *puVar1 = param_1;
      puVar1[1] = param_1[1];
      *(undefined4 **)param_1[1] = puVar1;
      param_1[1] = (int)puVar1;
      return;
    }
    if (puVar1[2] == param_2) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return;
}


