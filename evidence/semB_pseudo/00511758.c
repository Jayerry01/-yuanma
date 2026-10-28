int FUN_00511758(undefined4 param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  byte bVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte bVar9;
  byte *pbVar10;
  char *pcVar11;
  char *pcVar12;
  byte *pbVar13;
  bool bVar14;
  longlong lVar15;
  char local_1c8;
  char local_1c7 [351];
  byte local_68 [32];
  undefined4 *local_48;
  undefined2 local_42;
  uint local_40;
  byte local_3c;
  undefined1 local_3b;
  byte local_39;
  int local_38;
  byte *local_34;
  byte *local_30;
  undefined8 local_2c;
  int local_24;
  int local_20;
  byte local_1c;
  char local_1b;
  char local_1a;
  char local_19;
  uint local_18;
  char local_13;
  char local_12;
  char local_11;
  int local_10;
  char local_9;
  int local_8;
  
  local_19 = '\0';
  bVar1 = *param_2;
  local_8 = 0;
  local_38 = 0;
  pbVar10 = param_2;
  do {
    if (bVar1 == 0) {
LAB_0051215e:
      if (local_18 == 0xffffffff) {
LAB_00512164:
        if ((local_38 == 0) && (local_19 == '\0')) {
          local_38 = -1;
        }
      }
      return local_38;
    }
    if (DAT_005ca8ec < 2) {
      uVar4 = (byte)PTR_DAT_005ca6e0[(uint)bVar1 * 2] & 8;
    }
    else {
      uVar4 = FUN_0050a85c(bVar1,8);
    }
    if (uVar4 != 0) {
      local_8 = local_8 + -1;
      uVar5 = FUN_005121e5(&local_8,param_1,param_1);
      FUN_005121ce(uVar5);
      iVar6 = FUN_0050be69(pbVar10[1]);
      pbVar13 = pbVar10;
      while (pbVar10 = pbVar13 + 1, iVar6 != 0) {
        iVar6 = FUN_0050be69(pbVar13[2]);
        pbVar13 = pbVar10;
      }
    }
    if (*pbVar10 == 0x25) {
      local_39 = 0;
      local_1c = 0;
      local_1b = '\0';
      local_12 = '\0';
      local_13 = '\0';
      local_1a = '\0';
      iVar6 = 0;
      local_9 = '\0';
      local_20 = 0;
      local_24 = 0;
      local_10 = 0;
      local_11 = '\x01';
      local_34 = (byte *)0x0;
      do {
        uVar4 = (uint)pbVar10[1];
        param_2 = pbVar10 + 1;
        if (DAT_005ca8ec < 2) {
          uVar7 = (byte)PTR_DAT_005ca6e0[uVar4 * 2] & 4;
        }
        else {
          uVar7 = FUN_0050a85c(uVar4,4);
        }
        if (uVar7 == 0) {
          if (uVar4 < 0x4f) {
            if (uVar4 != 0x4e) {
              if (uVar4 == 0x2a) {
                local_12 = local_12 + '\x01';
              }
              else if (uVar4 != 0x46) {
                if (uVar4 == 0x49) {
                  if ((pbVar10[2] != 0x36) || (pbVar10[3] != 0x34)) goto LAB_005118b3;
                  local_34 = local_34 + 1;
                  local_2c = 0;
                  param_2 = pbVar10 + 3;
                }
                else if (uVar4 == 0x4c) {
                  local_11 = local_11 + '\x01';
                }
                else {
LAB_005118b3:
                  local_13 = local_13 + '\x01';
                }
              }
            }
          }
          else if (uVar4 == 0x68) {
            local_11 = local_11 + -1;
            local_9 = local_9 + -1;
          }
          else {
            if (uVar4 == 0x6c) {
              local_11 = local_11 + '\x01';
            }
            else if (uVar4 != 0x77) goto LAB_005118b3;
            local_9 = local_9 + '\x01';
          }
        }
        else {
          local_24 = local_24 + 1;
          local_10 = (uVar4 - 0x30) + local_10 * 10;
        }
        pbVar10 = param_2;
      } while (local_13 == '\0');
      puVar2 = param_3;
      if (local_12 == '\0') {
        local_30 = (byte *)*param_3;
        puVar2 = param_3 + 1;
        local_48 = param_3;
      }
      param_3 = puVar2;
      local_13 = '\0';
      if (local_9 == '\0') {
        if ((*param_2 == 0x53) || (*param_2 == 0x43)) {
          local_9 = '\x01';
        }
        else {
          local_9 = -1;
        }
      }
      uVar4 = *param_2 | 0x20;
      local_40 = uVar4;
      if (uVar4 != 0x6e) {
        if ((uVar4 == 99) || (uVar4 == 0x7b)) {
          local_8 = local_8 + 1;
          local_18 = FUN_005121b4(param_1);
        }
        else {
          local_18 = FUN_005121e5(&local_8,param_1);
        }
      }
      if ((local_24 != 0) && (local_10 == 0)) {
LAB_0051213e:
        local_8 = local_8 + -1;
        FUN_005121ce(local_18,param_1);
        goto LAB_0051215e;
      }
      if (uVar4 < 0x70) {
        if (uVar4 == 0x6f) {
LAB_00511e6b:
          if (local_18 == 0x2d) {
            local_1b = '\x01';
          }
          else if (local_18 != 0x2b) goto LAB_00511ea0;
          local_10 = local_10 + -1;
          if ((local_10 == 0) && (local_24 != 0)) {
            local_13 = '\x01';
          }
          else {
            local_8 = local_8 + 1;
            local_18 = FUN_005121b4(param_1);
          }
          goto LAB_00511ea0;
        }
        if (uVar4 != 99) {
          if (uVar4 == 100) goto LAB_00511e6b;
          if (uVar4 < 0x65) {
LAB_00511be3:
            if (*param_2 != local_18) goto LAB_0051213e;
            local_19 = local_19 + -1;
            if (local_12 == '\0') {
              param_3 = local_48;
            }
            goto LAB_005120bf;
          }
          if (0x67 < uVar4) {
            if (uVar4 == 0x69) {
              uVar4 = 100;
              goto LAB_005119a1;
            }
            if (uVar4 != 0x6e) goto LAB_00511be3;
            iVar6 = local_8;
            lVar15 = local_2c;
            if (local_12 != '\0') goto LAB_005120bf;
            goto LAB_00512099;
          }
          pcVar11 = &local_1c8;
          if (local_18 == 0x2d) {
            local_1c8 = '-';
            pcVar11 = local_1c7;
LAB_005119d7:
            local_10 = local_10 + -1;
            local_8 = local_8 + 1;
            local_18 = FUN_005121b4(param_1);
          }
          else if (local_18 == 0x2b) goto LAB_005119d7;
          if ((local_24 == 0) || (0x15d < local_10)) {
            local_10 = 0x15d;
          }
          while( true ) {
            uVar4 = local_18;
            if (DAT_005ca8ec < 2) {
              uVar7 = (byte)PTR_DAT_005ca6e0[local_18 * 2] & 4;
            }
            else {
              uVar7 = FUN_0050a85c(local_18,4);
            }
            if ((uVar7 == 0) ||
               (iVar6 = local_10 + -1, bVar14 = local_10 == 0, local_10 = iVar6, bVar14)) break;
            local_20 = local_20 + 1;
            *pcVar11 = (char)uVar4;
            pcVar11 = pcVar11 + 1;
            local_8 = local_8 + 1;
            local_18 = FUN_005121b4(param_1);
          }
          if ((DAT_005ca8f0 == (char)uVar4) &&
             (iVar6 = local_10 + -1, bVar14 = local_10 != 0, local_10 = iVar6, bVar14)) {
            local_8 = local_8 + 1;
            uVar4 = FUN_005121b4(param_1);
            *pcVar11 = DAT_005ca8f0;
            while( true ) {
              pcVar11 = pcVar11 + 1;
              local_18 = uVar4;
              if (DAT_005ca8ec < 2) {
                uVar7 = (byte)PTR_DAT_005ca6e0[uVar4 * 2] & 4;
              }
              else {
                uVar7 = FUN_0050a85c(uVar4,4);
              }
              if ((uVar7 == 0) ||
                 (iVar6 = local_10 + -1, bVar14 = local_10 == 0, local_10 = iVar6, bVar14)) break;
              local_20 = local_20 + 1;
              *pcVar11 = (char)uVar4;
              local_8 = local_8 + 1;
              uVar4 = FUN_005121b4(param_1);
            }
          }
          pcVar12 = pcVar11;
          if ((local_20 != 0) &&
             (((uVar4 == 0x65 || (uVar4 == 0x45)) &&
              (iVar6 = local_10 + -1, bVar14 = local_10 != 0, local_10 = iVar6, bVar14)))) {
            *pcVar11 = 'e';
            pcVar12 = pcVar11 + 1;
            local_8 = local_8 + 1;
            uVar4 = FUN_005121b4(param_1);
            local_18 = uVar4;
            if (uVar4 == 0x2d) {
              *pcVar12 = '-';
              pcVar12 = pcVar11 + 2;
LAB_00511afe:
              bVar14 = local_10 != 0;
              local_10 = local_10 + -1;
              if (bVar14) goto LAB_00511b0d;
              local_10 = 0;
            }
            else if (uVar4 == 0x2b) goto LAB_00511afe;
            while( true ) {
              if (DAT_005ca8ec < 2) {
                uVar7 = (byte)PTR_DAT_005ca6e0[uVar4 * 2] & 4;
              }
              else {
                uVar7 = FUN_0050a85c(uVar4,4);
              }
              if ((uVar7 == 0) ||
                 (iVar6 = local_10 + -1, bVar14 = local_10 == 0, local_10 = iVar6, bVar14)) break;
              local_20 = local_20 + 1;
              *pcVar12 = (char)uVar4;
              pcVar12 = pcVar12 + 1;
LAB_00511b0d:
              local_8 = local_8 + 1;
              uVar4 = FUN_005121b4(param_1);
              local_18 = uVar4;
            }
          }
          local_8 = local_8 + -1;
          FUN_005121ce(uVar4,param_1);
          if (local_20 != 0) {
            if (local_12 == '\0') {
              local_38 = local_38 + 1;
              *pcVar12 = '\0';
              (*(code *)PTR_FUN_005cccd0)(local_11 + -1,local_30,&local_1c8);
            }
            goto LAB_005120bf;
          }
          goto LAB_0051215e;
        }
        if (local_24 == 0) {
          local_10 = local_10 + 1;
          local_24 = 1;
        }
        if ('\0' < local_9) {
          local_1a = '\x01';
        }
        pcVar11 = &DAT_005cd268;
LAB_00511cc4:
        local_1c = 0xff;
        pbVar10 = (byte *)pcVar11;
        pbVar13 = param_2;
LAB_00511cc8:
        param_2 = pbVar13;
        _memset(local_68,0,0x20);
        if ((local_40 == 0x7b) && (*pbVar10 == 0x5d)) {
          uVar4 = 0x5d;
          local_68[0xb] = 0x20;
          pbVar10 = pbVar10 + 1;
        }
        else {
          uVar4 = (uint)local_39;
        }
        while (pbVar13 = local_30, bVar1 = *pbVar10, bVar1 != 0x5d) {
          if (((bVar1 == 0x2d) && (bVar9 = (byte)uVar4, bVar9 != 0)) &&
             (bVar3 = pbVar10[1], bVar3 != 0x5d)) {
            if (bVar3 <= bVar9) {
              uVar4 = (uint)bVar3;
              bVar3 = bVar9;
            }
            if ((byte)uVar4 <= bVar3) {
              iVar6 = (bVar3 - uVar4) + 1;
              do {
                local_68[uVar4 >> 3] = local_68[uVar4 >> 3] | '\x01' << ((byte)uVar4 & 7);
                uVar4 = uVar4 + 1;
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
            }
            uVar4 = 0;
            pbVar10 = pbVar10 + 2;
          }
          else {
            uVar4 = (uint)bVar1;
            local_68[bVar1 >> 3] = local_68[bVar1 >> 3] | '\x01' << (bVar1 & 7);
            pbVar10 = pbVar10 + 1;
          }
        }
        if (*pbVar10 == 0) goto LAB_0051215e;
        if (local_40 == 0x7b) {
          param_2 = pbVar10;
        }
        local_8 = local_8 + -1;
        local_34 = local_30;
        FUN_005121ce(local_18,param_1);
        while( true ) {
          if ((local_24 != 0) &&
             (iVar6 = local_10 + -1, bVar14 = local_10 == 0, local_10 = iVar6, bVar14))
          goto LAB_00511e2d;
          local_8 = local_8 + 1;
          local_18 = FUN_005121b4(param_1);
          if ((local_18 == 0xffffffff) ||
             (bVar1 = (byte)local_18,
             ((int)(char)(local_68[(int)local_18 >> 3] ^ local_1c) & 1 << (bVar1 & 7)) == 0)) break;
          if (local_12 == '\0') {
            if (local_1a == '\0') {
              *pbVar13 = bVar1;
              pbVar13 = pbVar13 + 1;
              local_30 = pbVar13;
            }
            else {
              local_3c = bVar1;
              if ((PTR_DAT_005ca6e0[(local_18 & 0xff) * 2 + 1] & 0x80) != 0) {
                local_8 = local_8 + 1;
                local_3b = FUN_005121b4(param_1);
              }
              FUN_00513afc(&local_42,&local_3c,DAT_005ca8ec);
              *(undefined2 *)pbVar13 = local_42;
              pbVar13 = pbVar13 + 2;
              local_30 = pbVar13;
            }
          }
          else {
            local_34 = local_34 + 1;
          }
        }
        local_8 = local_8 + -1;
        FUN_005121ce(local_18,param_1);
LAB_00511e2d:
        if (local_34 == pbVar13) goto LAB_0051215e;
        if ((local_12 == '\0') && (local_38 = local_38 + 1, local_40 != 99)) {
          if (local_1a == '\0') {
            *local_30 = 0;
          }
          else {
            local_30[0] = 0;
            local_30[1] = 0;
          }
        }
      }
      else {
        if (uVar4 == 0x70) {
          local_11 = '\x01';
          goto LAB_00511e6b;
        }
        if (uVar4 == 0x73) {
          if ('\0' < local_9) {
            local_1a = '\x01';
          }
          pcVar11 = s_____005cd260;
          goto LAB_00511cc4;
        }
        if (uVar4 == 0x75) goto LAB_00511e6b;
        if (uVar4 != 0x78) {
          if (uVar4 != 0x7b) goto LAB_00511be3;
          if ('\0' < local_9) {
            local_1a = '\x01';
          }
          pbVar10 = param_2 + 1;
          pbVar13 = pbVar10;
          if (*pbVar10 == 0x5e) {
            pcVar11 = (char *)(param_2 + 2);
            param_2 = pbVar10;
            goto LAB_00511cc4;
          }
          goto LAB_00511cc8;
        }
LAB_005119a1:
        if (local_18 == 0x2d) {
          local_1b = '\x01';
LAB_00511c30:
          local_10 = local_10 + -1;
          if ((local_10 == 0) && (local_24 != 0)) {
            local_13 = '\x01';
          }
          else {
            local_8 = local_8 + 1;
            local_18 = FUN_005121b4(param_1);
          }
        }
        else if (local_18 == 0x2b) goto LAB_00511c30;
        if (local_18 == 0x30) {
          local_8 = local_8 + 1;
          local_18 = FUN_005121b4(param_1);
          if (((char)local_18 == 'x') || ((char)local_18 == 'X')) {
            local_8 = local_8 + 1;
            local_18 = FUN_005121b4(param_1);
            uVar4 = 0x78;
          }
          else {
            local_20 = 1;
            if (uVar4 == 0x78) {
              local_8 = local_8 + -1;
              FUN_005121ce(local_18,param_1);
              local_18 = 0x30;
            }
            else {
              uVar4 = 0x6f;
            }
          }
        }
LAB_00511ea0:
        lVar15 = local_2c;
        if (local_34 == (byte *)0x0) {
          if (local_13 == '\0') {
            while ((uVar7 = local_18, uVar4 != 0x78 && (uVar4 != 0x70))) {
              if (DAT_005ca8ec < 2) {
                uVar8 = (byte)PTR_DAT_005ca6e0[local_18 * 2] & 4;
              }
              else {
                uVar8 = FUN_0050a85c(local_18,4);
              }
              if (uVar8 == 0) goto LAB_00512067;
              if (uVar4 == 0x6f) {
                if (0x37 < (int)uVar7) goto LAB_00512067;
                iVar6 = iVar6 << 3;
              }
              else {
                iVar6 = iVar6 * 10;
              }
LAB_0051203f:
              local_20 = local_20 + 1;
              iVar6 = iVar6 + -0x30 + uVar7;
              if ((local_24 != 0) && (local_10 = local_10 + -1, lVar15 = local_2c, local_10 == 0))
              goto LAB_00512075;
              local_8 = local_8 + 1;
              local_18 = FUN_005121b4(param_1);
            }
            if (DAT_005ca8ec < 2) {
              uVar8 = (byte)PTR_DAT_005ca6e0[local_18 * 2] & 0x80;
            }
            else {
              uVar8 = FUN_0050a85c(local_18,0x80);
            }
            if (uVar8 != 0) {
              iVar6 = iVar6 << 4;
              uVar7 = FUN_0051217d(uVar7);
              local_18 = uVar7;
              goto LAB_0051203f;
            }
LAB_00512067:
            local_8 = local_8 + -1;
            FUN_005121ce(uVar7,param_1);
            lVar15 = local_2c;
          }
LAB_00512075:
          if (local_1b != '\0') {
            iVar6 = -iVar6;
          }
        }
        else {
          if (local_13 == '\0') {
            while (uVar7 = local_18, uVar4 != 0x78) {
              if (DAT_005ca8ec < 2) {
                uVar8 = (byte)PTR_DAT_005ca6e0[local_18 * 2] & 4;
              }
              else {
                uVar8 = FUN_0050a85c(local_18,4);
              }
              if (uVar8 == 0) goto LAB_00511f89;
              if (uVar4 == 0x6f) {
                if (0x37 < (int)uVar7) goto LAB_00511f89;
                lVar15 = __allshl();
              }
              else {
                lVar15 = __allmul(local_2c,10,0);
              }
LAB_00511f5b:
              local_20 = local_20 + 1;
              local_2c = lVar15 + (int)(uVar7 - 0x30);
              if ((local_24 != 0) && (local_10 = local_10 + -1, lVar15 = local_2c, local_10 == 0))
              goto LAB_00511f97;
              local_8 = local_8 + 1;
              local_18 = FUN_005121b4(param_1);
            }
            if (DAT_005ca8ec < 2) {
              uVar8 = (byte)PTR_DAT_005ca6e0[local_18 * 2] & 0x80;
            }
            else {
              uVar8 = FUN_0050a85c(local_18,0x80);
            }
            if (uVar8 != 0) {
              lVar15 = __allshl();
              local_2c = lVar15;
              uVar7 = FUN_0051217d(uVar7);
              local_18 = uVar7;
              lVar15 = local_2c;
              goto LAB_00511f5b;
            }
LAB_00511f89:
            local_8 = local_8 + -1;
            FUN_005121ce(uVar7,param_1);
            lVar15 = local_2c;
          }
LAB_00511f97:
          local_2c._4_4_ = (int)((ulonglong)lVar15 >> 0x20);
          local_2c._0_4_ = (int)lVar15;
          if (local_1b != '\0') {
            lVar15 = CONCAT44(-(local_2c._4_4_ + (uint)((int)local_2c != 0)),-(int)local_2c);
          }
        }
        if (uVar4 == 0x46) {
          local_20 = 0;
        }
        if (local_20 == 0) goto LAB_0051215e;
        local_2c = lVar15;
        if (local_12 == '\0') {
          local_38 = local_38 + 1;
LAB_00512099:
          local_2c = lVar15;
          if (local_34 == (byte *)0x0) {
            if (local_11 == '\0') {
              *(short *)local_30 = (short)iVar6;
            }
            else {
              *(int *)local_30 = iVar6;
            }
          }
          else {
            *(longlong *)local_30 = lVar15;
          }
        }
      }
LAB_005120bf:
      local_19 = local_19 + '\x01';
      param_2 = param_2 + 1;
    }
    else {
      local_8 = local_8 + 1;
      uVar4 = FUN_005121b4(param_1);
      param_2 = pbVar10 + 1;
      local_18 = uVar4;
      if (*pbVar10 != uVar4) goto LAB_0051213e;
      if ((PTR_DAT_005ca6e0[(uVar4 & 0xff) * 2 + 1] & 0x80) != 0) {
        local_8 = local_8 + 1;
        uVar7 = FUN_005121b4(param_1);
        bVar1 = *param_2;
        param_2 = pbVar10 + 2;
        if (bVar1 != uVar7) {
          local_8 = local_8 + -1;
          FUN_005121ce(uVar7,param_1);
          local_8 = local_8 + -1;
          FUN_005121ce(uVar4,param_1);
          goto LAB_0051215e;
        }
        local_8 = local_8 + -1;
      }
    }
    if ((local_18 == 0xffffffff) && ((*param_2 != 0x25 || (param_2[1] != 0x6e)))) goto LAB_00512164;
    bVar1 = *param_2;
    pbVar10 = param_2;
  } while( true );
}


