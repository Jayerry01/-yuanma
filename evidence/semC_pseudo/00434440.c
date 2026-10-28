void FUN_00434440(int param_1,int param_2,int param_3,char *param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *puVar8;
  int local_11c;
  int local_118;
  undefined4 local_114;
  int local_110;
  int local_10c;
  undefined4 local_108;
  undefined1 local_104 [4];
  undefined4 local_100 [64];
  
  if ((param_1 != 0) && (DAT_007f01e4 != 0)) {
    uVar4 = 0xffffffff;
    pcVar7 = param_4;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    local_110 = ~uVar4 - 1;
    local_114 = FUN_0041f6b0(param_5,param_6,param_7);
    param_3 = param_3 - DAT_00724300;
    iVar6 = 0;
    if (0 < (int)(~uVar4 - 1)) {
      do {
        bVar2 = param_4[iVar6];
        uVar3 = (ushort)bVar2;
        if ((char)bVar2 < '\0') {
          iVar6 = iVar6 + 1;
          uVar3 = CONCAT11(bVar2,param_4[iVar6]);
        }
        puVar8 = local_100;
        for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
        FUN_0041fe00(uVar3,local_100,0x100,local_104,&local_118,&local_11c,&local_108,&local_10c);
        iVar5 = DAT_007eac60;
        if (local_10c <= DAT_007eac60) {
          iVar5 = local_10c;
        }
        FUN_00433880(param_1,local_100,(iVar5 - local_11c) / 2 + param_2,
                     (DAT_007f18d0 - local_118) + param_3 + -1,local_11c,local_108,local_114);
        param_2 = param_2 + DAT_005c4310 + iVar5;
        iVar6 = iVar6 + 1;
      } while (iVar6 < local_110);
    }
  }
  return;
}


