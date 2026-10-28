undefined1 FUN_0053b040(int param_1)

{
  short sVar1;
  char cVar2;
  undefined4 in_EAX;
  uint uVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  byte unaff_SI;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  sVar1 = *(short *)(param_1 + 0x1c);
  iVar4 = CONCAT22((short)((uint)in_EAX >> 0x10),sVar1);
  if (sVar1 == 1) {
    cVar2 = FUN_0052c880(*(undefined4 *)(param_1 + 0x12),*(undefined4 *)(param_1 + 0x16),1,1,0x1900,
                         0x1401,0);
    if (cVar2 == '\0') {
      return 0;
    }
    DAT_0072329c[10] = 0x601;
    uVar3 = FUN_00530d80(6);
    DAT_0072329c[0xb] = uVar3;
    if (DAT_0072329c[0xb] == 0) {
      return 0;
    }
    DAT_0072329c[0xc] = 6;
    DAT_0072329c[0xd] = 0x404;
    iVar4 = (*DAT_007dc850)(DAT_0072329c[0xb],1,6);
    if (iVar4 != 6) {
      return 0;
    }
    uVar3 = *DAT_0072329c;
    (*DAT_007dc854)(*(undefined4 *)(param_1 + 10),0);
    uVar10 = 0;
    if (DAT_0072329c[1] != 0) {
      do {
        uVar7 = 0;
        if (*DAT_0072329c != 0) {
          do {
            iVar4 = (*DAT_007dc850)(&stack0xfffffff0,1,1);
            if (iVar4 != 1) {
              return 0;
            }
            uVar6 = 0x80;
            uVar9 = 0;
            uVar8 = *DAT_0072329c;
            do {
              bVar5 = (byte)uVar6;
              uVar6 = uVar6 >> 1;
              *(bool *)(uVar8 * uVar10 + DAT_0072329c[5] + uVar7) = (unaff_SI & bVar5) != 0;
              uVar7 = uVar7 + 1;
              uVar8 = *DAT_0072329c;
              if (uVar8 <= uVar7) break;
              uVar9 = uVar9 + 1;
            } while (uVar9 < 8);
          } while (uVar7 < *DAT_0072329c);
        }
        (*DAT_007dc854)(-uVar3 >> 3 & 3,1);
        uVar10 = uVar10 + 1;
        if (DAT_0072329c[1] <= uVar10) {
          return 1;
        }
      } while( true );
    }
  }
  else if (sVar1 == 4) {
    cVar2 = FUN_0052c880(*(undefined4 *)(param_1 + 0x12),*(undefined4 *)(param_1 + 0x16),1,1,0x1900,
                         0x1401,0);
    if (cVar2 == '\0') {
      return 0;
    }
    DAT_0072329c[10] = 0x601;
    uVar3 = FUN_00530d80(0x30);
    DAT_0072329c[0xb] = uVar3;
    if (DAT_0072329c[0xb] == 0) {
      return 0;
    }
    DAT_0072329c[0xc] = 0x30;
    DAT_0072329c[0xd] = 0x404;
    iVar4 = (*DAT_007dc850)(DAT_0072329c[0xb],1,0x30);
    if (iVar4 != 0x30) {
      return 0;
    }
    uVar3 = *DAT_0072329c;
    (*DAT_007dc854)(*(undefined4 *)(param_1 + 10),0);
    uVar10 = 0;
    if (DAT_0072329c[1] != 0) {
      do {
        uVar7 = 0;
        if (*DAT_0072329c != 0) {
          do {
            iVar4 = (*DAT_007dc850)(&stack0xfffffff0,1,1);
            if (iVar4 != 1) {
              return 0;
            }
            uVar8 = uVar7 + 1;
            *(byte *)(*DAT_0072329c * uVar10 + DAT_0072329c[5] + -1 + uVar8) = unaff_SI >> 4;
            if (uVar8 == *DAT_0072329c) break;
            *(byte *)(*DAT_0072329c * uVar10 + DAT_0072329c[5] + uVar8) = unaff_SI & 0xf;
            uVar7 = uVar7 + 2;
          } while (uVar7 < *DAT_0072329c);
        }
        (*DAT_007dc854)(-uVar3 >> 1 & 3,1);
        uVar10 = uVar10 + 1;
        if (DAT_0072329c[1] <= uVar10) {
          return 1;
        }
      } while( true );
    }
  }
  else {
    if (sVar1 == 8) {
      DAT_0072329c[8] = 0x1900;
      uVar3 = FUN_00530d80(0x300);
      DAT_0072329c[0xb] = uVar3;
      if (DAT_0072329c[0xb] == 0) {
        return 0;
      }
      DAT_0072329c[0xc] = 0x300;
      DAT_0072329c[0xd] = 0x404;
      iVar4 = (*DAT_007dc850)(DAT_0072329c[0xb],1,0x300);
      if (iVar4 != 0x300) {
        return 0;
      }
    }
    cVar2 = FUN_0052c880(*(undefined4 *)(param_1 + 0x12),*(undefined4 *)(param_1 + 0x16),1,
                         CONCAT22((short)((uint)iVar4 >> 0x10),*(undefined2 *)(param_1 + 0x1c)) >> 3
                         ,0x80e0,0x1401,0);
    if (cVar2 == '\0') {
      return 0;
    }
    DAT_0072329c[10] = 0x601;
    if (*(short *)(param_1 + 0x1c) == 0x20) {
      DAT_0072329c[8] = 0x80e1;
    }
    (*DAT_007dc854)(*(undefined4 *)(param_1 + 10),0);
    uVar3 = DAT_0072329c[4];
    if ((-uVar3 & 3) == 0) {
      uVar3 = (*DAT_007dc850)(DAT_0072329c[5],1,DAT_0072329c[6]);
      if (uVar3 != DAT_0072329c[6]) {
        return 0;
      }
    }
    else {
      uVar10 = 0;
      if (DAT_0072329c[1] != 0) {
        do {
          uVar7 = (*DAT_007dc850)(DAT_0072329c[4] * uVar10 + DAT_0072329c[5],1,DAT_0072329c[4]);
          if (uVar7 != DAT_0072329c[4]) {
            return 0;
          }
          (*DAT_007dc854)(-uVar3 & 3,1);
          uVar10 = uVar10 + 1;
        } while (uVar10 < DAT_0072329c[1]);
      }
    }
  }
  return 1;
}


