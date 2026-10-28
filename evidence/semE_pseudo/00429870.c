void FUN_00429870(void)

{
  int *piVar1;
  
  piVar1 = &DAT_007dff60;
  do {
    if (*piVar1 != 0) {
      FUN_004325b0(*piVar1);
      FUN_00432970(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x7e035c);
  thunk_FUN_00432af0();
  FUN_00432340();
  return;
}



bool thunk_FUN_004325f0(short param_1,int param_2,ushort param_3)

{
  ushort uVar1;
  int iVar2;
  undefined2 uStack_14;
  short sStack_12;
  int iStack_10;
  int iStack_c;
  undefined4 uStack_8;
  undefined2 uStack_4;
  
  if (DAT_005d5b30 == (int *)0x0) {
    return false;
  }
  sStack_12 = param_1;
  uVar1 = (param_3 >> 3) * param_1;
  uStack_8 = CONCAT22(param_3,uVar1);
  uStack_14 = 1;
  iStack_c = (uint)uVar1 * param_2;
  iStack_10 = param_2;
  uStack_4 = 0;
  iVar2 = (**(code **)(*DAT_005d5b30 + 0x38))(DAT_005d5b30,&uStack_14);
  return iVar2 == 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 thunk_FUN_004329c0(void)

{
  UINT_PTR UVar1;
  MCIERROR MVar2;
  UINT_PTR uDeviceID;
  undefined4 uStack_150;
  MCIDEVICEID MStack_14c;
  char *pcStack_148;
  undefined1 auStack_13c [4];
  undefined4 uStack_138;
  tagAUXCAPSA tStack_130;
  CHAR aCStack_100 [256];
  
  if (DAT_005d5b40 != 0) {
    return 0;
  }
  if (DAT_005d5a00 == 0) {
    return 0;
  }
  uStack_150 = *(undefined4 *)(DAT_005d5a0c + 0x6e4);
  pcStack_148 = s_cdaudio_005c7304;
  MVar2 = mciSendCommandA(0,0x803,0x2102,(DWORD_PTR)&uStack_150);
  if (MVar2 != 0) {
    mciGetErrorStringA(MVar2,aCStack_100,0xff);
    return 0;
  }
  DAT_005d5b40 = MStack_14c;
  uStack_138 = 10;
  MVar2 = mciSendCommandA(MStack_14c,0x80d,0x402,(DWORD_PTR)auStack_13c);
  if (MVar2 == 0) {
    _DAT_005d5b38 = waveOutGetNumDevs();
    DAT_005d5b3c = auxGetNumDevs();
    uDeviceID = 0;
    UVar1 = _DAT_005c7228;
    if (DAT_005d5b3c != 0) {
      while (auxGetDevCapsA(uDeviceID,&tStack_130,0x30), UVar1 = uDeviceID,
            tStack_130.wTechnology != 1) {
        uDeviceID = uDeviceID + 1;
        if (DAT_005d5b3c <= uDeviceID) {
          return 1;
        }
      }
    }
    _DAT_005c7228 = UVar1;
    return 1;
  }
  mciGetErrorStringA(MVar2,aCStack_100,0x100);
  FUN_00410c60(aCStack_100);
  return 0;
}



undefined4 thunk_FUN_00432af0(void)

{
  int iVar1;
  
  if (DAT_005d5b40 == 0) {
    return 0;
  }
  iVar1 = FUN_00432b40();
  if (iVar1 != 0) {
    mciSendCommandA(DAT_005d5b40,0x808,0,0);
  }
  mciSendCommandA(DAT_005d5b40,0x804,0,0);
  DAT_005d5b40 = 0;
  return 1;
}


