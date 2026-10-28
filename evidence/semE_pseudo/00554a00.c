undefined4 FUN_00554a00(void)

{
  int iVar1;
  WSADATA local_190;
  
  DAT_0072683c = DAT_0072683c + 1;
  if (DAT_0072683c == 1) {
    iVar1 = WSAStartup(0x101,&local_190);
    if (iVar1 != 0) {
      DAT_0072683c = 0;
      WSACleanup();
      return 0;
    }
  }
  return 1;
}


