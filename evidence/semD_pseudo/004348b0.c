void FUN_004348b0(int *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if ((param_1 != (int *)0x0) || (param_1 = DAT_005d9b78, DAT_005d9b78 != (int *)0x0)) {
    uVar4 = param_1[5];
    if (uVar4 == 0) {
      param_1[1] = *param_2;
      param_1[2] = param_2[1];
      param_1[3] = param_2[2];
      param_1[4] = param_2[3];
    }
    else {
      iVar3 = uVar4 - 1;
      iVar1 = *param_2;
      iVar5 = iVar3;
      if (iVar1 <= iVar3) {
        iVar5 = iVar1;
      }
      if (iVar5 < 0) {
        iVar3 = 0;
      }
      else if (iVar1 <= iVar3) {
        iVar3 = iVar1;
      }
      param_1[1] = iVar3;
      uVar2 = param_2[2];
      if ((int)(((int)uVar2 < 1) - 1 & uVar2) < (int)uVar4) {
        uVar4 = ((int)uVar2 < 1) - 1 & uVar2;
      }
      param_1[3] = uVar4;
      uVar4 = param_1[6];
      iVar1 = param_2[1];
      iVar3 = uVar4 - 1;
      iVar5 = iVar3;
      if (iVar1 <= iVar3) {
        iVar5 = iVar1;
      }
      if (iVar5 < 0) {
        iVar3 = 0;
      }
      else if (iVar1 <= iVar3) {
        iVar3 = iVar1;
      }
      param_1[2] = iVar3;
      uVar2 = param_2[3];
      if ((int)(((int)uVar2 < 1) - 1 & uVar2) < (int)uVar4) {
        uVar4 = ((int)uVar2 < 1) - 1 & uVar2;
      }
      param_1[4] = uVar4;
    }
    FUN_004345a0(param_1);
    FUN_00433d10(*(undefined4 *)(*param_1 + param_1[0xc] * 4),param_1 + 1);
  }
  return;
}


