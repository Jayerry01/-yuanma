uint FUN_005056a0(int param_1)

{
  uint uVar1;
  char *pcVar2;
  
  uVar1 = param_1 - 1;
  if ((-1 < (int)uVar1) && (uVar1 < (uint)(DAT_00667570 - DAT_0066756c >> 6))) {
    pcVar2 = (char *)(uVar1 * 0x40 + DAT_0066756c);
    return (uint)pcVar2 & -(uint)(*pcVar2 != '\0');
  }
  return 0;
}


