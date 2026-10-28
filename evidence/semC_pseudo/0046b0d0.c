undefined4 __thiscall FUN_0046b0d0(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  byte local_68 [52];
  byte local_34 [52];
  
  iVar6 = *(int *)(param_1 + 0x3c);
  if ((iVar6 == 0) && (*(int *)(param_2 + 0x3c) == 0)) {
    iVar5 = 0;
    bVar9 = true;
    iVar6 = *(int *)(*(int *)(param_1 + 0x20) + 8);
    if (iVar6 != *(int *)(param_1 + 0x20)) {
      do {
        pbVar7 = local_34;
        for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
          pbVar7[0] = 0;
          pbVar7[1] = 0;
          pbVar7[2] = 0;
          pbVar7[3] = 0;
          pbVar7 = pbVar7 + 4;
        }
        pbVar7[0] = 0;
        pbVar7[1] = 0;
        pbVar7 = local_68;
        for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
          pbVar7[0] = 0;
          pbVar7[1] = 0;
          pbVar7[2] = 0;
          pbVar7[3] = 0;
          pbVar7 = pbVar7 + 4;
        }
        pbVar7[0] = 0;
        pbVar7[1] = 0;
        FUN_004663c0(local_34,iVar5);
        FUN_004663c0(local_68,iVar5);
        pbVar7 = local_68;
        pbVar3 = local_34;
        do {
          bVar1 = *pbVar3;
          bVar8 = bVar1 < *pbVar7;
          if (bVar1 != *pbVar7) {
LAB_0046b177:
            iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_0046b17c;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          bVar8 = bVar1 < pbVar7[1];
          if (bVar1 != pbVar7[1]) goto LAB_0046b177;
          pbVar3 = pbVar3 + 2;
          pbVar7 = pbVar7 + 2;
        } while (bVar1 != 0);
        iVar4 = 0;
LAB_0046b17c:
        if (iVar4 != 0) {
          bVar9 = false;
        }
        iVar4 = *(int *)(iVar6 + 0xc);
        if (iVar4 == 0) {
          iVar4 = *(int *)(iVar6 + 4);
          if (iVar6 == *(int *)(iVar4 + 0xc)) {
            do {
              iVar6 = iVar4;
              iVar4 = *(int *)(iVar6 + 4);
            } while (iVar6 == *(int *)(iVar4 + 0xc));
          }
          if (*(int *)(iVar6 + 0xc) != iVar4) {
            iVar6 = iVar4;
          }
        }
        else {
          for (iVar2 = *(int *)(iVar4 + 8); iVar6 = iVar4, iVar2 != 0; iVar2 = *(int *)(iVar2 + 8))
          {
            iVar4 = iVar2;
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar6 != *(int *)(param_1 + 0x20));
      if (!bVar9) {
        return 0;
      }
    }
  }
  else {
    pbVar7 = (byte *)(iVar6 + 0x50);
    pbVar3 = (byte *)(*(int *)(param_2 + 0x3c) + 0x50);
    do {
      bVar1 = *pbVar7;
      bVar9 = bVar1 < *pbVar3;
      if (bVar1 != *pbVar3) {
LAB_0046b214:
        iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_0046b219;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar7[1];
      bVar9 = bVar1 < pbVar3[1];
      if (bVar1 != pbVar3[1]) goto LAB_0046b214;
      pbVar7 = pbVar7 + 2;
      pbVar3 = pbVar3 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_0046b219:
    if ((iVar5 != 0) || (*(short *)(iVar6 + 0xc) != *(short *)(*(int *)(param_2 + 0x3c) + 0xc))) {
      return 0;
    }
  }
  return 1;
}


