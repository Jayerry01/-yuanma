void FUN_004331d0(int param_1,undefined4 param_2,undefined4 param_3,int *param_4,int param_5,
                 uint param_6,int *param_7,uint *param_8,uint *param_9,uint param_10,int param_11)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 *puVar7;
  uint *puVar8;
  undefined4 local_fc [4];
  int local_ec;
  int local_d8;
  undefined4 local_80 [4];
  int local_70;
  int local_5c;
  uint local_40;
  
  if (((DAT_007eabe0 == 0x10) && (0 < (int)param_10)) && (0 < param_11)) {
    puVar7 = local_80;
    for (iVar4 = 0x1f; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    local_80[0] = 0x7c;
    DAT_007e2768 = -0x7789fde4;
    do {
      DAT_007e2768 = (**(code **)(*param_7 + 100))(param_7,0,local_80,0,0);
    } while (DAT_007e2768 == -0x7789fde4);
    DAT_007e2768 = -0x7789fde4;
    puVar7 = local_fc;
    for (iVar4 = 0x1f; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    local_fc[0] = 0x7c;
    do {
      DAT_007e2768 = (**(code **)(*param_4 + 100))(param_4,0,local_fc,0,0);
    } while (DAT_007e2768 == -0x7789fde4);
    param_9 = (uint *)(local_5c + local_70 * (int)param_9 + (int)param_8 * 2);
    param_8 = (uint *)(local_d8 + local_ec * param_6 + param_5 * 2);
    if ((DAT_007f18e4 == 1) || (param_6 = 0x3def3def, DAT_007f18e4 == 2)) {
      param_6 = 0x7bef7bef;
    }
    if (param_1 == 0) {
      if (0 < param_11) {
        do {
          uVar5 = param_10 >> 1;
          puVar6 = param_9;
          puVar8 = param_8;
          do {
            *puVar8 = (*puVar8 >> 1 & param_6) + (*puVar6 >> 1 & param_6);
            puVar6 = puVar6 + 1;
            puVar8 = puVar8 + 1;
            uVar5 = uVar5 - 1;
          } while (uVar5 != 0);
          param_8 = (uint *)((int)param_8 + local_ec);
          param_9 = (uint *)((int)param_9 + local_70);
          param_11 = param_11 + -1;
        } while (param_11 != 0);
      }
    }
    else if (0 < param_11) {
      do {
        uVar5 = param_10 >> 1;
        puVar6 = param_9;
        puVar8 = param_8;
        do {
          uVar3 = *puVar6;
          if ((local_40 << 0x10 | local_40 & 0xffff) != uVar3) {
            uVar1 = *puVar8;
            sVar2 = (short)uVar3;
            if ((short)local_40 == sVar2) {
              uVar3 = CONCAT22((short)(uVar3 >> 0x10),(short)uVar1);
            }
            else if (CONCAT22((short)local_40,sVar2) == uVar3) {
              uVar3 = CONCAT22((short)(uVar1 >> 0x10),sVar2);
            }
            *puVar8 = (uVar1 >> 1 & param_6) + (uVar3 >> 1 & param_6);
          }
          puVar6 = puVar6 + 1;
          puVar8 = puVar8 + 1;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
        param_9 = (uint *)((int)param_9 + local_70);
        param_8 = (uint *)((int)param_8 + local_ec);
        param_11 = param_11 + -1;
      } while (param_11 != 0);
    }
    (**(code **)(*param_7 + 0x80))(param_7,0);
    (**(code **)(*param_4 + 0x80))(param_4,0);
  }
  return;
}


