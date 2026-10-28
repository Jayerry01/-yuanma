bool __thiscall FUN_00554710(SOCKET *param_1,undefined4 param_2)

{
  int iVar1;
  sockaddr local_10;
  
  if (*param_1 == 0xffffffff) {
    return false;
  }
  FUN_00554760(param_2,&local_10);
  iVar1 = bind(*param_1,&local_10,0x10);
  return iVar1 == 0;
}


