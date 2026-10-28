undefined4 * __thiscall FUN_005856c0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a6a18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_005811c0(param_2,param_3);
  local_4 = 0;
  *param_1 = &PTR_FUN_005b1038;
  param_1[1] = 10;
  param_1[3] = 0x268;
  pcVar2 = (char *)FUN_0058a6d0(10);
  pcVar3 = (char *)(param_1 + 5);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00581aa0(&DAT_005d2f20);
  FUN_00477200();
  FUN_00477200();
  FUN_00477200();
  FUN_00477200();
  ExceptionList = local_c;
  return param_1;
}


