bool __fastcall FUN_00554c30(SOCKET *param_1)

{
  int iVar1;
  fd_set local_104;
  
  local_104.fd_array[0] = *param_1;
  if (local_104.fd_array[0] == 0xffffffff) {
    return false;
  }
  local_104.fd_count = 1;
  iVar1 = select(local_104.fd_array[0] + 1,(fd_set *)0x0,(fd_set *)0x0,&local_104,
                 (timeval *)&DAT_00726840);
  return 0 < iVar1;
}



int WSAGetLastError(void)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00554c80. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = WSAGetLastError();
  return iVar1;
}


