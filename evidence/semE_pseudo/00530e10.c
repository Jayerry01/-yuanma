void FUN_00530e10(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    DAT_00723294 = (undefined1 *)param_1;
    DAT_00723298 = (undefined1 *)param_2;
    return;
  }
  if ((DAT_00723294 == (undefined1 *)0x0) || (DAT_00723298 == (undefined1 *)0x0)) {
    DAT_00723294 = &LAB_00530d70;
    DAT_00723298 = &LAB_00530df0;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

char thunk_FUN_0050a9d0(byte *param_1,byte *param_2)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  
  iVar2 = _DAT_007f1d4c;
  if (DAT_00667844 == 0) {
    bVar5 = 0xff;
    do {
      do {
        if (bVar5 == 0) {
          return '\0';
        }
        bVar5 = *param_2;
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar4 == bVar5);
      bVar3 = bVar5 + 0xbf + (-((byte)(bVar5 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar4 + 0xbf;
      bVar5 = bVar4 + (-(bVar4 < 0x1a) & 0x20U) + 0x41;
    } while (bVar5 == bVar3);
    cVar6 = (bVar5 < bVar3) * -2 + '\x01';
  }
  else {
    LOCK();
    _DAT_007f1d4c = _DAT_007f1d4c + 1;
    UNLOCK();
    bVar1 = 0 < DAT_007f1d48;
    if (bVar1) {
      LOCK();
      UNLOCK();
      _DAT_007f1d4c = iVar2;
      FUN_0050dd18(0x13);
    }
    uVar7 = (uint)bVar1;
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_0050aa7f;
        bVar5 = *param_2;
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      bVar4 = FUN_0050a791(bVar4,bVar5);
      bVar5 = FUN_0050a791();
    } while (bVar4 == bVar5);
    cVar6 = (bVar4 < bVar5) * -2 + '\x01';
LAB_0050aa7f:
    if (uVar7 == 0) {
      LOCK();
      _DAT_007f1d4c = _DAT_007f1d4c + -1;
      UNLOCK();
    }
    else {
      FUN_0050dd79(0x13);
    }
  }
  return cVar6;
}


