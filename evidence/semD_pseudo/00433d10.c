void FUN_00433d10(int param_1,int *param_2)

{
  int *piVar1;
  
  if ((param_1 != 0) || (param_1 = DAT_005d9b74, DAT_005d9b74 != 0)) {
    piVar1 = (int *)(param_1 + 0x20);
    if (param_2 == (int *)0x0) {
      *piVar1 = 0;
      *(undefined4 *)(param_1 + 0x24) = 0;
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0xc);
    }
    else {
      *piVar1 = *param_2;
      *(int *)(param_1 + 0x24) = param_2[1];
      *(int *)(param_1 + 0x28) = param_2[2];
      *(int *)(param_1 + 0x2c) = param_2[3];
    }
    if ((*(int *)(param_1 + 0x28) - *piVar1 == *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x10))
       && (*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24) ==
           *(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x14))) {
      *(undefined4 *)(param_1 + 0x30) = 0;
      return;
    }
    *(undefined4 *)(param_1 + 0x30) = 1;
  }
  return;
}


