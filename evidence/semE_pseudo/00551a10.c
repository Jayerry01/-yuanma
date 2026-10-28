char FUN_00551a10(undefined4 *param_1)

{
  if (DAT_005d11a8 != '\0') {
    DAT_00725b1c = FUN_00551a60(&DAT_00725b20);
    if (DAT_00725b1c == '\0') {
      FUN_00551d60(&DAT_00725b20);
    }
    DAT_005d11a8 = '\0';
  }
  *param_1 = DAT_00725b20;
  *(undefined2 *)(param_1 + 1) = DAT_00725b24;
  return DAT_00725b1c;
}


