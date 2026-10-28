void FUN_0050b62d(void)

{
  longlong lVar1;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  lVar1 = __allmul(local_c.dwHighDateTime,0,0,1);
  __aulldiv((lVar1 - CONCAT44(_DAT_0066765c,_DAT_00667658)) + (ulonglong)local_c.dwLowDateTime,10000
            ,0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
