void FUN_00544b60(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  short *psVar2;
  byte *pbVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_188;
  byte local_180 [128];
  undefined1 local_100 [256];
  
  iVar8 = *(int *)(*(int *)(param_1 + 0x1a8) + 0x18);
  iVar6 = (param_4 >> 2) * 0x20 + 4;
  iVar4 = (param_3 >> 3) * 0x20 + 2;
  iVar7 = (param_2 >> 2) * 0x20 + 4;
  uVar1 = FUN_00544c70(param_1,iVar7,iVar4,iVar6,local_100);
  FUN_00544e50(param_1,iVar7,iVar4,iVar6,uVar1,local_100,local_180);
  pbVar3 = local_180;
  local_188 = 4;
  piVar5 = (int *)(iVar8 + (param_2 >> 2) * 0x10);
  do {
    iVar4 = 8;
    iVar8 = ((param_3 >> 3) * 0x100 + (param_4 >> 2) * 4) * 2;
    do {
      iVar6 = 4;
      psVar2 = (short *)(*piVar5 + iVar8);
      do {
        *psVar2 = *pbVar3 + 1;
        psVar2 = psVar2 + 1;
        pbVar3 = pbVar3 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      iVar8 = iVar8 + 0x40;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    piVar5 = piVar5 + 1;
    local_188 = local_188 + -1;
  } while (local_188 != 0);
  return;
}


