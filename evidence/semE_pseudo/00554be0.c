bool __fastcall FUN_00554be0(SOCKET *param_1)

{
  int iVar1;
  fd_set local_104;
  
  local_104.fd_array[0] = *param_1;
  if (local_104.fd_array[0] == 0xffffffff) {
    return false;
  }
  local_104.fd_count = 1;
  iVar1 = select(local_104.fd_array[0] + 1,(fd_set *)0x0,&local_104,(fd_set *)0x0,
                 (timeval *)&DAT_00726840);
  return 0 < iVar1;
}


