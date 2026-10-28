undefined4 FUN_0052eb20(int param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  
  if (DAT_0072329c == (int *)0x0) {
    FUN_00530d00(0x506);
    return 0;
  }
  if (param_1 == DAT_0072329c[8]) {
    if (param_2 == DAT_0072329c[9]) {
      return 1;
    }
  }
  else if ((param_2 == DAT_0072329c[9]) && (cVar1 = FUN_00539ec0(param_1), cVar1 != '\0')) {
    DAT_0072329c[8] = param_1;
    return 1;
  }
  cVar1 = FUN_0052b240(0x635);
  if (cVar1 != '\0') {
    FUN_0052eca0(DAT_0072329c);
  }
  iVar3 = FUN_0052e890(DAT_0072329c,param_1,param_2);
  if (iVar3 != 0) {
    DAT_0072329c[8] = param_1;
    DAT_0072329c[9] = param_2;
    uVar2 = FUN_00530f00(param_2);
    *(undefined1 *)((int)DAT_0072329c + 0xd) = uVar2;
    uVar2 = FUN_00530eb0(param_1);
    *(undefined1 *)(DAT_0072329c + 3) = uVar2;
    DAT_0072329c[4] =
         (uint)*(byte *)((int)DAT_0072329c + 0xd) * (uint)*(byte *)(DAT_0072329c + 3) *
         *DAT_0072329c;
    DAT_0072329c[7] = DAT_0072329c[4] * DAT_0072329c[1];
    DAT_0072329c[6] = DAT_0072329c[7] * DAT_0072329c[2];
    if (((DAT_0072329c[0xb] != 0) && (DAT_0072329c[0xc] != 0)) && (DAT_0072329c[0xd] != 0x400)) {
      FUN_00530db0(DAT_0072329c[0xb]);
    }
    DAT_0072329c[0xb] = *(int *)(iVar3 + 0x2c);
    DAT_0072329c[0xc] = *(int *)(iVar3 + 0x30);
    DAT_0072329c[0xd] = *(int *)(iVar3 + 0x34);
    *(undefined4 *)(iVar3 + 0x2c) = 0;
    FUN_00530db0(DAT_0072329c[5]);
    DAT_0072329c[5] = *(int *)(iVar3 + 0x14);
    *(undefined4 *)(iVar3 + 0x14) = 0;
    FUN_0052c1a0(iVar3);
    return 1;
  }
  return 0;
}


