undefined4 FUN_0053bfb0(int *param_1)

{
  undefined1 *puVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auStack_c [4];
  uint local_8;
  uint uStack_4;
  
  uVar8 = param_1[2] * param_1[1] * (uint)*(byte *)(param_1 + 3) * *param_1;
  uVar7 = 0;
  local_8 = uVar8;
  iVar3 = FUN_0052bca0(0x665);
  if (iVar3 != 0x660) {
    if (uVar8 != 0) {
      do {
        bVar2 = (*DAT_007dc870)();
        if ((char)bVar2 < '\0') {
          uVar8 = (uint)*(byte *)(param_1 + 3);
          uVar5 = (*DAT_007dc850)(auStack_c,1,*(byte *)(param_1 + 3));
          if (uVar5 != uVar8) {
            return 0;
          }
          uVar5 = 0;
          uStack_4 = (bVar2 & 0x7f) + 1;
          uVar4 = uStack_4 * uVar8;
          if (uVar4 != 0) {
            do {
              iVar3 = 0;
              if (uVar8 != 0) {
                do {
                  puVar1 = auStack_c + iVar3;
                  iVar6 = param_1[5] + iVar3;
                  iVar3 = iVar3 + 1;
                  *(undefined1 *)(iVar6 + uVar5 + uVar7) = *puVar1;
                } while (iVar3 < (int)(uint)*(byte *)(param_1 + 3));
              }
              uVar8 = (uint)*(byte *)(param_1 + 3);
              uVar5 = uVar5 + uVar8;
            } while (uVar5 < uVar4);
          }
          iVar3 = *(byte *)(param_1 + 3) * uStack_4;
        }
        else {
          iVar3 = (bVar2 + 1) * (uint)*(byte *)(param_1 + 3);
          iVar6 = (*DAT_007dc850)(param_1[5] + uVar7,1,iVar3);
          if (iVar6 != iVar3) {
            return 0;
          }
        }
        uVar7 = uVar7 + iVar3;
      } while (uVar7 < local_8);
    }
    return 1;
  }
  FUN_005316e0(*(uint *)(DAT_0072329c + 0x18) >> 1);
  if (uVar8 != 0) {
    do {
      uVar8 = (*DAT_007dc870)();
      bVar2 = *(byte *)(param_1 + 3);
      if ((char)uVar8 < '\0') {
        uVar5 = (uint)bVar2;
        uVar4 = (*DAT_007dc850)(auStack_c,1,(uint)bVar2);
        if (uVar4 != uVar5) {
LAB_0053c0b8:
          FUN_00531770();
          return 0;
        }
        uVar4 = 0;
        uVar8 = ((uVar8 & 0x7f) + 1) * uVar5;
        if (uVar8 != 0) {
          do {
            iVar3 = 0;
            if (uVar5 != 0) {
              do {
                uStack_4 = uVar4;
                iVar6 = param_1[5] + iVar3;
                puVar1 = auStack_c + iVar3;
                iVar3 = iVar3 + 1;
                *(undefined1 *)(iVar6 + uVar4 + uVar7) = *puVar1;
                uVar4 = uStack_4;
              } while (iVar3 < (int)(uint)*(byte *)(param_1 + 3));
            }
            uVar5 = (uint)*(byte *)(param_1 + 3);
            uVar4 = uVar4 + uVar5;
          } while (uVar4 < uVar8);
        }
      }
      else {
        uVar8 = ((uVar8 & 0xff) + 1) * (uint)bVar2;
        uVar5 = (*DAT_007dc850)(param_1[5] + uVar7,1,uVar8);
        if (uVar5 != uVar8) goto LAB_0053c0b8;
      }
      uVar7 = uVar7 + uVar8;
    } while (uVar7 < local_8);
  }
  FUN_00531770();
  return 1;
}


