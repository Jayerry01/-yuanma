int __thiscall FUN_005548d0(SOCKET *param_1,char *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (*param_1 == 0xffffffff) {
    return -1;
  }
  iVar1 = send(*param_1,param_2,param_3,0);
  if ((iVar1 < 0) && ((char)param_1[1] != '\0')) {
    iVar2 = WSAGetLastError();
    if (iVar2 == 0x2733) {
      return 0;
    }
  }
  return iVar1;
}


