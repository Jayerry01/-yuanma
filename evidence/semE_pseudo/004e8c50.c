void __fastcall FUN_004e8c50(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  
  uVar3 = 0xffffffff;
  pcVar4 = (char *)(param_1 + 4);
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_004ea660();
  iVar2 = FUN_00514de0(~uVar3 + param_1,&DAT_005c9ef4,3);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0x44) = 1;
    FUN_004ea800();
    return;
  }
  FUN_004e90b0();
  return;
}


