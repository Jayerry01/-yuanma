char * FUN_00593634(char *param_1)

{
  char cVar1;
  size_t _Size;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  void *local_c;
  
  local_c = (void *)0x0;
  if (DAT_00667844 == 0) {
    cVar1 = *param_1;
    pcVar3 = param_1;
    while (cVar1 != '\0') {
      cVar1 = *pcVar3;
      if (('@' < cVar1) && (cVar1 < '[')) {
        *pcVar3 = cVar1 + ' ';
      }
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_007f1d4c);
    bVar4 = DAT_007f1d48 == 0;
    if (!bVar4) {
      InterlockedDecrement((LONG *)&DAT_007f1d4c);
      FUN_0050dd18(0x13);
    }
    if (DAT_00667844 == 0) {
      if (bVar4) {
        InterlockedDecrement((LONG *)&DAT_007f1d4c);
      }
      else {
        FUN_0050dd79(0x13);
      }
      cVar1 = *param_1;
      pcVar3 = param_1;
      while (cVar1 != '\0') {
        cVar1 = *pcVar3;
        if (('@' < cVar1) && (cVar1 < '[')) {
          *pcVar3 = cVar1 + ' ';
        }
        pcVar3 = pcVar3 + 1;
        cVar1 = *pcVar3;
      }
    }
    else {
      _Size = FUN_005108f6(DAT_00667844,0x100,param_1,0xffffffff,0,0,0,1);
      if (((_Size != 0) && (local_c = _malloc(_Size), local_c != (void *)0x0)) &&
         (iVar2 = FUN_005108f6(DAT_00667844,0x100,param_1,0xffffffff,local_c,_Size,0,1), iVar2 != 0)
         ) {
        FUN_0050f710(param_1,local_c);
      }
      if (bVar4) {
        InterlockedDecrement((LONG *)&DAT_007f1d4c);
      }
      else {
        FUN_0050dd79(0x13);
      }
      FUN_005089fd(local_c);
    }
  }
  return param_1;
}


