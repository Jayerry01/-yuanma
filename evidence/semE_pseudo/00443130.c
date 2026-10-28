void FUN_00443130(int param_1)

{
  if (param_1 < 0x15) {
    Sleep(0);
    return;
  }
  Sleep(1 << ((char)param_1 - 0x14U & 0x1f));
  return;
}


