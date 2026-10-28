undefined4 __thiscall FUN_005694e0(int param_1,int param_2,byte param_3)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x120);
  if (((iVar2 != 0) && (-1 < param_2)) && (param_2 < *(int *)(iVar2 + 0x18))) {
    *(int *)(param_1 + 0x144) = param_2;
    piVar1 = (int *)(*(int *)(iVar2 + 0xc) + param_2 * 8);
    *(int **)(param_1 + 0x150) = piVar1;
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x138) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x140) = 0xbf800000;
      *(int *)(param_1 + 0x134) = *piVar1;
      *(float *)(param_1 + 0x13c) = (float)*piVar1;
      if ((param_3 & 1) != 0) {
        *(undefined4 *)(param_1 + 0x14c) = 0;
        return 1;
      }
      *(undefined4 *)(param_1 + 0x14c) = 1;
      return 1;
    }
  }
  return 0;
}


