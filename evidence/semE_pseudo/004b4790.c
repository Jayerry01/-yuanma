int * __thiscall FUN_004b4790(int *param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  
  *param_1 = 0;
  puVar1 = _malloc(0x2b8);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = (undefined1 *)FUN_00403440(0x2b8);
  }
  *param_1 = (int)puVar1;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = *param_2;
  *puVar1 = 0;
  *(undefined4 *)(*param_1 + 4) = 0;
  *(int *)(*param_1 + 8) = *param_1;
  *(int *)(*param_1 + 0xc) = *param_1;
  return param_1;
}


