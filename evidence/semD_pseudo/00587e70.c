int __thiscall FUN_00587e70(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  bool bVar6;
  
  if (*(int *)(param_1 + 0x2e8) != 0) {
    iVar5 = 0;
    iVar2 = FUN_0056b1d0();
    if (0 < iVar2) {
      do {
        pbVar3 = (byte *)FUN_0056b310(iVar5);
        pbVar4 = param_2;
        do {
          bVar1 = *pbVar3;
          bVar6 = bVar1 < *pbVar4;
          if (bVar1 != *pbVar4) {
LAB_00587ec1:
            iVar2 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
            goto LAB_00587ec6;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          bVar6 = bVar1 < pbVar4[1];
          if (bVar1 != pbVar4[1]) goto LAB_00587ec1;
          pbVar3 = pbVar3 + 2;
          pbVar4 = pbVar4 + 2;
        } while (bVar1 != 0);
        iVar2 = 0;
LAB_00587ec6:
        if (iVar2 == 0) {
          return iVar5;
        }
        iVar5 = iVar5 + 1;
        iVar2 = FUN_0056b1d0();
      } while (iVar5 < iVar2);
    }
  }
  return -1;
}


