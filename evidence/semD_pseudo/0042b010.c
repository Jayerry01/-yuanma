undefined4 FUN_0042b010(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  
  if (param_1 == (byte *)0x0) {
    return 0;
  }
  pbVar4 = (byte *)&DAT_005d5a24;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0042b04e:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_0042b053;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0042b04e;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0042b053:
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = FUN_00509f8f(param_1,&DAT_005c67d0);
  if (iVar3 == 0) {
    return 0;
  }
  FUN_00509e57(iVar3);
  return 1;
}


