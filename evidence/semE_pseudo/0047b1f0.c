undefined4 FUN_0047b1f0(undefined4 param_1)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = FUN_0047b1d0(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  if (DAT_005f16c8 != 0) {
    QueryPerformanceCounter((LARGE_INTEGER *)(iVar1 + 8));
    return 1;
  }
  DVar2 = timeGetTime();
  *(DWORD *)(iVar1 + 4) = DVar2;
  return 1;
}


