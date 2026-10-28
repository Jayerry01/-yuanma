void FUN_0058b810(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0072becc;
  iVar1 = DAT_0072bec8;
  for (iVar3 = DAT_0072bec8; iVar3 != iVar2; iVar3 = iVar3 + 0x14) {
    FUN_004815f0(0);
  }
  iVar3 = (int)((ulonglong)((longlong)(iVar2 - iVar1) * -0x66666667) >> 0x20);
  DAT_0072becc = DAT_0072becc + ((iVar3 >> 3) - (iVar3 >> 0x1f)) * 0x14;
  return;
}


