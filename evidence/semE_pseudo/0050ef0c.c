undefined4 FUN_0050ef0c(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  FUN_0050dcef();
  DAT_005cccc0 = TlsAlloc();
  if (DAT_005cccc0 != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_0050b4c3(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_005cccc0,lpTlsValue);
      if (BVar1 != 0) {
        FUN_0050ef60(lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}


