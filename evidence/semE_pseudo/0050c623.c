void FUN_0050c623(uint param_1)

{
  if ((0x5ca93f < param_1) && (param_1 < 0x5caba1)) {
    FUN_0050dd79(((int)(param_1 - 0x5ca940) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}


