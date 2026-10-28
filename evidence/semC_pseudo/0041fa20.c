void FUN_0041fa20(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint local_20 [4];
  uint local_10 [4];
  
  if (param_1 == param_3) {
    if (param_2 == param_4) {
      FUN_0041fcc0(param_1,param_2,param_5);
      return;
    }
    FUN_004200f0(param_1,param_2,param_4,param_5);
    return;
  }
  if (param_2 == param_4) {
    FUN_00420040(param_1,param_3,param_2,param_5);
    return;
  }
  iVar1 = *(int *)(DAT_005d5a0c + 0x68c);
  iVar3 = *(int *)(DAT_005d5a0c + 0x690);
  do {
    uVar4 = (uint)(param_1 < 0);
    local_20[1] = (uint)(iVar1 <= param_1);
    local_20[2] = (uint)(param_2 < 0);
    local_20[3] = (uint)(iVar3 <= param_2);
    local_10[0] = (uint)(param_3 < 0);
    local_10[1] = (uint)(iVar1 <= param_3);
    local_10[2] = (uint)(param_4 < 0);
    local_20[0] = uVar4;
    local_10[3] = (uint)(iVar3 <= param_4);
    iVar5 = 0;
    do {
      if ((local_20[iVar5] != 0) || (local_10[iVar5] != 0)) break;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
    if (iVar5 == 4) {
      iVar1 = param_2;
      iVar3 = param_1;
      if (param_4 < param_2) {
        iVar1 = param_4;
        iVar3 = param_3;
        param_4 = param_2;
        param_3 = param_1;
      }
      param_3 = param_3 - iVar3;
      if (param_3 < 1) {
        param_3 = -param_3;
        uVar6 = 0xffffffff;
      }
      else {
        uVar6 = 1;
      }
      if (param_3 <= param_4 - iVar1) {
        FUN_00420290(iVar3,iVar1,param_3,param_4 - iVar1,uVar6,param_5);
        return;
      }
      FUN_004201a0();
      return;
    }
    iVar5 = 0;
    do {
      if ((local_20[iVar5] != 0) && (local_10[iVar5] != 0)) break;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
    if (iVar5 != 4) {
      return;
    }
    iVar5 = param_2;
    iVar2 = param_1;
    if ((((uVar4 == 0) && (iVar1 <= param_1 == 0)) && (param_2 < 0 == 0)) && (iVar3 <= param_2 == 0)
       ) {
      uVar4 = (uint)(param_3 < 0);
      local_20[1] = (uint)(iVar1 <= param_3);
      local_20[2] = (uint)(param_4 < 0);
      local_20[3] = (uint)(iVar3 <= param_4);
      iVar5 = param_4;
      iVar2 = param_3;
      param_4 = param_2;
      param_3 = param_1;
    }
    param_2 = iVar5;
    param_1 = iVar2;
    if (uVar4 != 0) {
      param_2 = __ftol();
      param_1 = 0;
    }
    if (local_20[1] != 0) {
      param_1 = iVar1 + -1;
      param_2 = __ftol();
    }
    if (local_20[2] != 0) {
      param_1 = __ftol();
      param_2 = 0;
    }
    if (local_20[3] != 0) {
      param_2 = iVar3 + -1;
      param_1 = __ftol();
    }
  } while( true );
}


