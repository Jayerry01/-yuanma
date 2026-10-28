void FUN_00523590(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  char acStack_10c [8];
  int *piStack_104;
  undefined4 *puStack_100;
  int *piStack_fc;
  undefined4 *puStack_f8;
  undefined4 *puStack_f4;
  undefined4 uStack_f0;
  undefined4 auStack_74 [29];
  
  puVar3 = &DAT_007e32c0;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  DAT_007e32c0 = 0x7c;
  DAT_007e32c4 = 7;
  DAT_007e32cc = 400;
  DAT_007e32c8 = 0x14;
  DAT_007e3328 = 0x40;
  piStack_fc = *(int **)(DAT_005d5a0c + 0x6ec);
  uStack_f0 = 0;
  puStack_f4 = &DAT_00667a08;
  puStack_f8 = &DAT_007e32c0;
  puStack_100 = (undefined4 *)0x5235f6;
  (**(code **)(*piStack_fc + 0x18))();
  puStack_100 = (undefined4 *)0x0;
  piStack_104 = DAT_00667a08;
  builtin_strncpy(acStack_10c + 4,"\x046R",4);
  FUN_004219f0();
  puStack_100 = auStack_74;
  puVar3 = auStack_74;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  piStack_104 = (int *)0x1000400;
  acStack_10c[4] = '\0';
  acStack_10c[5] = '\0';
  acStack_10c[6] = '\0';
  acStack_10c[7] = '\0';
  auStack_74[0] = 100;
  acStack_10c[0] = '\0';
  acStack_10c[1] = '\0';
  acStack_10c[2] = '\0';
  acStack_10c[3] = '\0';
  (**(code **)(*DAT_00667a08 + 0x14))(DAT_00667a08,0);
  FUN_0040e740(s_Times_New_Roman_005cf4b8,0x10,0x10);
  puVar3 = &DAT_007e32c0;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  DAT_007e32c0 = 0x7c;
  do {
    iVar1 = (**(code **)(*DAT_00667a08 + 100))(DAT_00667a08,0,&DAT_007e32c0,0,0);
  } while (iVar1 == -0x7789fde4);
  DAT_005d9b80 = DAT_007e32cc;
  DAT_005d9b84 = DAT_007e32c8;
  pcVar4 = s_F_BCD_l1r969j9m_g2i0d0e0k_jIfnht_005cf457;
  uVar2 = 0xffffffff;
  iVar1 = 0;
  do {
    pcVar4 = pcVar4 + 1;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
  } while (*pcVar4 != '\0');
  DAT_005d9b7c = DAT_007e32d0;
  if (0 < (int)(~uVar2 - 1) / 2) {
    do {
      pcVar4 = s_F_BCD_l1r969j9m_g2i0d0e0k_jIfnht_005cf457;
      acStack_10c[iVar1] = s_F_BCD_l1r969j9m_g2i0d0e0k_jIfnht_005cf457[iVar1 * 2 + 1];
      uVar2 = 0xffffffff;
      iVar1 = iVar1 + 1;
      do {
        pcVar4 = pcVar4 + 1;
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
      } while (*pcVar4 != '\0');
    } while (iVar1 < (int)(~uVar2 - 1) / 2);
  }
  acStack_10c[iVar1] = '\0';
  FUN_00434440(DAT_007e32e4,1,0x14,acStack_10c,0x40,0x40,0x40);
  FUN_00434440(DAT_007e32e4,1,0x13,acStack_10c,0xff,0x40,0x40);
  FUN_00434440(DAT_007e32e4,0,0x13,acStack_10c,0xff,0x40,0x40);
  (**(code **)(*DAT_00667a08 + 0x80))(DAT_00667a08,0);
  return;
}


