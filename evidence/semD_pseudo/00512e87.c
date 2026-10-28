int FUN_00512e87(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_0066786c == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_0066786c = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_0066786c != (FARPROC)0x0) {
        DAT_00667870 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_00667874 = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_00512ed6;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_00512ed6:
    if (DAT_00667870 != (FARPROC)0x0) {
      iVar1 = (*DAT_00667870)();
      if ((iVar1 != 0) && (DAT_00667874 != (FARPROC)0x0)) {
        iVar1 = (*DAT_00667874)(iVar1);
      }
    }
    iVar1 = (*DAT_0066786c)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}


