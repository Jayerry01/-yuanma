void FUN_0050b670(void)

{
  longlong lVar1;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  lVar1 = __allmul(local_c.dwHighDateTime,0,0,1);
  _DAT_00667658 = lVar1 + (ulonglong)local_c.dwLowDateTime;
  return;
}


