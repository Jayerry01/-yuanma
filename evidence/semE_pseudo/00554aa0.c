void __thiscall FUN_00554aa0(SOCKET *param_1,undefined4 param_2)

{
  int iVar1;
  int local_14;
  sockaddr local_10;
  
  if (*param_1 != 0xffffffff) {
    local_14 = 0x10;
    iVar1 = getsockname(*param_1,&local_10,&local_14);
    if (iVar1 == 0) {
      FUN_005548a0(param_2,&local_10);
    }
  }
  return;
}


