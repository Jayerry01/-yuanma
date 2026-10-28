void FUN_00511616(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_007f2dc0)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
