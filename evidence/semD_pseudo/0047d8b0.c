FUN_0047d8b0(undefined4 param_1,undefined4 param_2,float param_3,float param_4,undefined4 param_5,
            undefined4 param_6)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_4;
  
  iVar2 = FUN_0047c1e0((DAT_005c8128 + 1) * DAT_005c8124 * 2,DAT_005c8128 * DAT_005c8124 * 2,
                       DAT_005c8128 * DAT_005c8124 * 6);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = DAT_005c8124 + -1;
  iVar4 = 0;
  iVar5 = 0;
  iVar3 = 0;
  local_4 = param_3 * 0.017453292;
  if (0 < DAT_005c8124) {
    do {
      fVar1 = ((param_4 - param_3) * 0.017453292) / (float)iVar2 + local_4;
      FUN_0047d2f0(iVar3,param_1,param_2,local_4,fVar1,param_5,param_6,iVar4,iVar5);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 2 + DAT_005c8128 * 2;
      iVar5 = iVar5 + DAT_005c8128 * 6;
      local_4 = fVar1;
    } while (iVar3 < DAT_005c8124);
  }
  return 1;
}


