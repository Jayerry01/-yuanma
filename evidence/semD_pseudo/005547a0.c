int __thiscall FUN_005547a0(SOCKET *param_1,char *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  sockaddr local_10;
  
  if (*param_1 == 0xffffffff) {
    return -1;
  }
  FUN_00554760(param_4,&local_10);
  iVar1 = sendto(*param_1,param_2,param_3,0,&local_10,0x10);
  if ((iVar1 < 0) && ((char)param_1[1] != '\0')) {
    iVar2 = WSAGetLastError();
    if (iVar2 == 0x2733) {
      return 0;
    }
  }
  return iVar1;
}


