DWORD * FUN_0050ef73(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_005cccc0);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)FUN_0050b4c3(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_005cccc0,lpTlsValue);
      if (BVar1 != 0) {
        FUN_0050ef60(lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        goto LAB_0050efce;
      }
    }
    __amsg_exit(0x10);
  }
LAB_0050efce:
  SetLastError(dwErrCode);
  return lpTlsValue;
}


