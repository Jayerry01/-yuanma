void FUN_00433c80(int param_1,int *param_2)

{
  int *piVar1;
  
  if ((param_1 != 0) || (param_1 = DAT_005d9b74, DAT_005d9b74 != 0)) {
    piVar1 = (int *)(param_1 + 0x10);
    if (param_2 == (int *)0x0) {
      *piVar1 = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0xc);
    }
    else {
      *piVar1 = *param_2;
      *(int *)(param_1 + 0x14) = param_2[1];
      *(int *)(param_1 + 0x18) = param_2[2];
      *(int *)(param_1 + 0x1c) = param_2[3];
    }
    if ((*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20) == *(int *)(param_1 + 0x18) - *piVar1)
       && (*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24) ==
           *(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x14))) {
      *(undefined4 *)(param_1 + 0x30) = 0;
      return;
    }
    *(undefined4 *)(param_1 + 0x30) = 1;
  }
  return;
}


