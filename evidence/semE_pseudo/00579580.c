void __thiscall FUN_00579580(undefined4 *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  
  *param_1 = 1;
  iVar2 = 0x50 - (int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)param_1 + iVar2] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_005795d0();
  return;
}


