void FUN_004a8160(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  size_t _Count;
  char *pcVar3;
  
  uVar2 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  _Count = 0;
  if (-1 < (int)(~uVar2 - 1)) {
    do {
      if (param_1[_Count] == '.') break;
      _Count = _Count + 1;
    } while ((int)_Count <= (int)(~uVar2 - 1));
  }
  _strncpy(param_2,param_1,_Count);
  param_2[_Count] = '\0';
  if (param_3 != 0) {
    FUN_00508ae6(param_3,&DAT_005c67ac,param_1 + _Count);
  }
  return;
}


