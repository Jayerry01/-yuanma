undefined4 * __thiscall FUN_00588720(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a6b48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_005811c0(param_2,param_3);
  local_4 = 0;
  *param_1 = &PTR_LAB_005b1258;
  param_1[1] = 6;
  param_1[3] = 0x2ac;
  pcVar2 = (char *)FUN_0058a6d0(6);
  pcVar3 = (char *)(param_1 + 5);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  *(undefined1 *)(param_1 + 0x9a) = 0;
  if (param_1[0x7b] != 0) {
    *(undefined1 *)(param_1[0x7b] + 0x29) = 0;
    *(undefined1 *)(param_1[0x7b] + 0x28) = 0;
  }
  param_1[0x9b] = 0x3e4ccccd;
  param_1[0x9c] = 0x14;
  param_1[0xa8] = 0;
  param_1[0xa7] = 0;
  param_1[0xaa] = 0;
  param_1[0xa9] = 0;
  FUN_00581aa0(&DAT_005d2f60);
  FUN_00477200();
  ExceptionList = local_c;
  return param_1;
}


