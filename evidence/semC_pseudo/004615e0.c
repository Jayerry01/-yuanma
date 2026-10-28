FUN_004615e0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,char *param_6
            ,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *puVar7;
  int local_120;
  uint local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  int local_10c;
  int local_108;
  int local_104;
  undefined4 local_100 [64];
  
  uVar3 = 0xffffffff;
  pcVar6 = param_6;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  if ((int)(~uVar3 - 1) < param_7) {
    param_7 = ~uVar3 - 1;
  }
  local_110 = FUN_0041f6b0(param_8,param_9,param_10);
  local_118 = FUN_00429f90(param_2,param_3);
  iVar5 = 0;
  if (0 < param_7) {
    do {
      local_11c = (uint)(byte)param_6[iVar5];
      puVar7 = local_100;
      for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      FUN_00461770(local_11c,local_100,0x100,&local_104,&local_120,&local_10c,&local_114,&local_108)
      ;
      iVar2 = local_108;
      iVar4 = local_104;
      if (local_108 != 0) {
        iVar4 = (local_108 - local_10c) / 2;
      }
      FUN_00433880(local_118,local_100,iVar4 + param_4,
                   (*(int *)(param_1 + 0x18) - local_120) + param_5,local_10c,local_114,local_110);
      param_4 = param_4 + iVar2;
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_7);
  }
  FUN_00429fd0(param_2,param_3);
  return 1;
}



undefined4 __thiscall