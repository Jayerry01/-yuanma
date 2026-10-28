void __thiscall FUN_004aac40(int *param_1,int *param_2,int param_3)

{
  undefined1 uVar1;
  int *piVar2;
  int **ppiVar3;
  uint uVar4;
  int *local_4;
  
  piVar2 = param_2;
  if ((undefined1 *)*param_1 != (undefined1 *)param_1[1]) {
    *(undefined1 *)*param_1 = 0;
    param_1[1] = *param_1;
  }
  uVar4 = 0;
  local_4 = param_1;
  if (param_3 != 0xc) {
    do {
      uVar1 = *(undefined1 *)(uVar4 + (int)piVar2);
      if (param_1[1] + 1 == param_1[2]) {
        param_2 = (int *)0x1;
        local_4 = (int *)(param_1[1] - *param_1);
        ppiVar3 = &param_2;
        if (local_4 != (int *)0x0) {
          ppiVar3 = &local_4;
        }
        FUN_0049be40((int)*ppiVar3 + (int)local_4);
      }
      FUN_00402bc0(param_1[1] + 1);
      *(undefined1 *)param_1[1] = uVar1;
      uVar4 = uVar4 + 1;
      param_1[1] = param_1[1] + 1;
    } while (uVar4 < param_3 - 0xcU);
  }
  param_1[9] = (uint)*(byte *)(param_3 + -0xc + (int)piVar2);
  param_1[10] = (uint)*(byte *)(param_3 + -8 + (int)piVar2);
  uVar4 = (uint)*(byte *)(param_3 + -4 + (int)piVar2);
  param_1[0x15] = uVar4 & 2;
  param_1[0xf] = uVar4 & 1;
  param_1[0x11] = uVar4 & 4;
  param_1[0x12] = uVar4 & 8;
  param_1[0x10] = uVar4 & 0x10;
  param_1[0x13] = uVar4 & 0x20;
  return;
}


