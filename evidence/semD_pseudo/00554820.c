int __thiscall FUN_00554820(SOCKET *param_1,char *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int local_14;
  sockaddr local_10;
  
  if (*param_1 == 0xffffffff) {
    return -1;
  }
  local_14 = 0x10;
  iVar1 = recvfrom(*param_1,param_2,param_3,0,&local_10,&local_14);
  if ((iVar1 < 0) && ((char)param_1[1] != '\0')) {
    iVar2 = WSAGetLastError();
    if (iVar2 == 0x2733) {
      return 0;
    }
  }
  FUN_005548a0(param_4,&local_10);
  return iVar1;
}


