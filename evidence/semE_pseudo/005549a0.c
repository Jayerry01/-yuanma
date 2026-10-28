undefined4 __thiscall FUN_005549a0(SOCKET *param_1,undefined4 param_2)

{
  int iVar1;
  sockaddr local_10;
  
  if (*param_1 == 0xffffffff) {
    return 0;
  }
  FUN_00554760(param_2,&local_10);
  iVar1 = connect(*param_1,&local_10,0x10);
  if (-1 < iVar1) {
    return 1;
  }
  if (((char)param_1[1] != '\0') && (iVar1 = WSAGetLastError(), iVar1 == 0x2733)) {
    return 1;
  }
  return 0;
}


