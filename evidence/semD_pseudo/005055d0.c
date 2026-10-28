uint FUN_005055d0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_40 [16];
  
  uVar1 = 0;
  uVar2 = (int)DAT_00667570 - (int)DAT_0066756c >> 6;
  pcVar4 = DAT_0066756c;
  if (uVar2 != 0) {
    do {
      if (*pcVar4 == '\0') {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
      pcVar4 = pcVar4 + 0x40;
    } while (uVar1 < uVar2);
  }
  if (DAT_00667570 == DAT_00667574) {
    FUN_00506a20(DAT_00667570,local_40);
  }
  else {
    if (DAT_00667570 != (undefined4 *)0x0) {
      puVar5 = local_40;
      puVar6 = DAT_00667570;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
    }
    DAT_00667570 = DAT_00667570 + 0x10;
  }
  return ((int)DAT_00667570 - (int)DAT_0066756c >> 6) - 1;
}


