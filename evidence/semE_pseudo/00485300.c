uint FUN_00485300(void)

{
  byte bVar1;
  
  if (0 < DAT_006658ec) {
    DAT_006658ec = DAT_006658ec + -1;
    bVar1 = *DAT_00665900;
    DAT_00665900 = DAT_00665900 + 1;
    return (uint)bVar1;
  }
  return 0xffffffff;
}


