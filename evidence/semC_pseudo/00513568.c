void FUN_00513568(void)

{
  char cVar1;
  char cVar2;
  char *_Str1;
  DWORD DVar3;
  int iVar4;
  size_t sVar5;
  char *_Source;
  int local_8;
  
  FUN_0050dd18(0xc);
  DAT_005cd348 = 0xffffffff;
  DAT_005cd338 = 0xffffffff;
  DAT_006678e0 = 0;
  _Str1 = (char *)FUN_00514f02(&DAT_005acda8);
  if (_Str1 == (char *)0x0) {
    FUN_0050dd79(0xc);
    DVar3 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_006678e8);
    if (DVar3 == 0xffffffff) {
      return;
    }
    DAT_005cd2a0 = DAT_006678e8 * 0x3c;
    DAT_006678e0 = 1;
    if (DAT_0066792e != 0) {
      DAT_005cd2a0 = DAT_005cd2a0 + DAT_0066793c * 0x3c;
    }
    if ((DAT_00667982 == 0) || (DAT_00667990 == 0)) {
      DAT_005cd2a4 = 0;
      _DAT_005cd2a8 = 0;
    }
    else {
      DAT_005cd2a4 = 1;
      _DAT_005cd2a8 = (DAT_00667990 - DAT_0066793c) * 0x3c;
    }
    iVar4 = WideCharToMultiByte(DAT_00667854,0x220,(LPCWSTR)&DAT_006678ec,-1,PTR_DAT_005cd32c,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar4 == 0) || (local_8 != 0)) {
      *PTR_DAT_005cd32c = 0;
    }
    else {
      PTR_DAT_005cd32c[0x3f] = 0;
    }
    iVar4 = WideCharToMultiByte(DAT_00667854,0x220,(LPCWSTR)&DAT_00667940,-1,PTR_DAT_005cd330,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar4 != 0) && (local_8 == 0)) {
      PTR_DAT_005cd330[0x3f] = 0;
      return;
    }
LAB_005137d9:
    *PTR_DAT_005cd330 = 0;
  }
  else {
    if ((*_Str1 != '\0') &&
       ((DAT_00667994 == (char *)0x0 || (iVar4 = _strcmp(_Str1,DAT_00667994), iVar4 != 0)))) {
      FUN_005089fd(DAT_00667994);
      sVar5 = _strlen(_Str1);
      DAT_00667994 = _malloc(sVar5 + 1);
      if (DAT_00667994 != (char *)0x0) {
        FUN_0050f710(DAT_00667994,_Str1);
        FUN_0050dd79(0xc);
        _strncpy(PTR_DAT_005cd32c,_Str1,3);
        _Source = _Str1 + 3;
        PTR_DAT_005cd32c[3] = 0;
        cVar1 = *_Source;
        if (cVar1 == '-') {
          _Source = _Str1 + 4;
        }
        iVar4 = FUN_005090d0(_Source);
        DAT_005cd2a0 = iVar4 * 0xe10;
        for (; (cVar2 = *_Source, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':'))));
            _Source = _Source + 1) {
        }
        if (*_Source == ':') {
          _Source = _Source + 1;
          iVar4 = FUN_005090d0(_Source);
          DAT_005cd2a0 = DAT_005cd2a0 + iVar4 * 0x3c;
          for (; ('/' < *_Source && (*_Source < ':')); _Source = _Source + 1) {
          }
          if (*_Source == ':') {
            _Source = _Source + 1;
            iVar4 = FUN_005090d0(_Source);
            DAT_005cd2a0 = DAT_005cd2a0 + iVar4;
            for (; ('/' < *_Source && (*_Source < ':')); _Source = _Source + 1) {
            }
          }
        }
        if (cVar1 == '-') {
          DAT_005cd2a0 = -DAT_005cd2a0;
        }
        DAT_005cd2a4 = (int)*_Source;
        if (DAT_005cd2a4 != 0) {
          _strncpy(PTR_DAT_005cd330,_Source,3);
          PTR_DAT_005cd330[3] = 0;
          return;
        }
        goto LAB_005137d9;
      }
    }
    FUN_0050dd79(0xc);
  }
  return;
}


