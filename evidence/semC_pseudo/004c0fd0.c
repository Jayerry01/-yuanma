void FUN_004c0fd0(void)

{
  float fVar1;
  char cVar2;
  int iVar3;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  undefined4 local_60;
  float local_5c;
  float local_50;
  undefined1 local_4c [12];
  undefined1 local_40 [64];
  
  fVar1 = DAT_00666240 * 300.0;
  FUN_00501830(local_40);
  FUN_00477d30(3,local_4c);
  FUN_00477d30(2,&local_70);
  local_88 = local_70 * -1.0;
  local_84 = local_6c * -1.0;
  local_80 = local_68 * -1.0;
  local_70 = local_88;
  local_6c = local_84;
  local_68 = local_80;
  if ((DAT_005c9a68 != -1) && (DAT_00666280 != '\0')) {
    iVar3 = FUN_004c2bf0(DAT_005c9a68);
    FUN_00477d30(2,&local_7c);
    local_74 = 0.0;
    FUN_0047ec40();
    local_50 = local_74 * fVar1;
    local_7c = local_7c * fVar1 * -0.3;
    local_78 = local_78 * fVar1 * -0.3;
    local_74 = local_50 * -0.3;
    FUN_00477d30(0,&local_88);
    local_80 = 0.0;
    FUN_0047ec40();
    local_50 = local_80 * fVar1;
    local_88 = local_88 * fVar1 * 0.3;
    local_84 = local_84 * fVar1 * 0.3;
    local_80 = local_50 * 0.3;
    if (DAT_00666284 != 0) {
      *(float *)(iVar3 + 4) = local_7c + *(float *)(iVar3 + 4);
      *(float *)(iVar3 + 8) = local_78 + *(float *)(iVar3 + 8);
      *(float *)(iVar3 + 0xc) = local_74 + *(float *)(iVar3 + 0xc);
    }
    if (DAT_00666288 != 0) {
      *(float *)(iVar3 + 4) = *(float *)(iVar3 + 4) - local_7c;
      *(float *)(iVar3 + 8) = *(float *)(iVar3 + 8) - local_78;
      *(float *)(iVar3 + 0xc) = *(float *)(iVar3 + 0xc) - local_74;
    }
    if (DAT_0066628c != 0) {
      *(float *)(iVar3 + 4) = local_88 + *(float *)(iVar3 + 4);
      *(float *)(iVar3 + 8) = local_84 + *(float *)(iVar3 + 8);
      *(float *)(iVar3 + 0xc) = local_80 + *(float *)(iVar3 + 0xc);
    }
    if (DAT_00666290 != 0) {
      *(float *)(iVar3 + 4) = *(float *)(iVar3 + 4) - local_88;
      *(float *)(iVar3 + 8) = *(float *)(iVar3 + 8) - local_84;
      *(float *)(iVar3 + 0xc) = *(float *)(iVar3 + 0xc) - local_80;
    }
    if (DAT_00666294 != 0) {
      *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar3 + 4);
      *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 8);
      *(float *)(iVar3 + 0xc) = *(float *)(iVar3 + 0xc) + 1.0;
    }
    if (DAT_00666298 != 0) {
      *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar3 + 4);
      *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 8);
      *(float *)(iVar3 + 0xc) = *(float *)(iVar3 + 0xc) - 1.0;
    }
  }
  cVar2 = FUN_004c13c0(local_4c,&local_70,&local_64);
  if (cVar2 != '\0') {
    DAT_00666234 = local_64;
    DAT_00666238 = local_60;
    DAT_0066623c = local_5c + 30.0;
    DAT_00666281 = 1;
    return;
  }
  DAT_00666281 = 0;
  return;
}


