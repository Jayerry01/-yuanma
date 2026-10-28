int __thiscall FUN_00584ab0(int param_1,int param_2,byte *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  bool bVar7;
  
  if ((-1 < param_2) && (param_2 <= *(int *)(param_1 + 0x91c))) {
    uVar2 = FUN_005598c0(*(undefined4 *)(param_1 + 0x28c + param_2 * 4));
    *(undefined4 *)(param_1 + 0x278 + param_2 * 4) = uVar2;
    iVar5 = 0;
    iVar3 = FUN_0056b1d0();
    if (0 < iVar3) {
      do {
        pbVar4 = (byte *)FUN_0056b310(iVar5);
        pbVar6 = param_3;
        do {
          bVar1 = *pbVar4;
          bVar7 = bVar1 < *pbVar6;
          if (bVar1 != *pbVar6) {
LAB_00584b22:
            iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
            goto LAB_00584b27;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar7 = bVar1 < pbVar6[1];
          if (bVar1 != pbVar6[1]) goto LAB_00584b22;
          pbVar4 = pbVar4 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        iVar3 = 0;
LAB_00584b27:
        if (iVar3 == 0) {
          return iVar5;
        }
        iVar5 = iVar5 + 1;
        iVar3 = FUN_0056b1d0();
      } while (iVar5 < iVar3);
    }
  }
  return -1;
}


