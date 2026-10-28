void __fastcall FUN_0058a310(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  FUN_00582000();
  iVar3 = -1;
  pcVar4 = (char *)(param_1 + 0x268);
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (iVar3 != -2) {
    uVar2 = FUN_005054e0(1);
    *(undefined4 *)(param_1 + 0x10) = uVar2;
    iVar3 = FUN_00505a10(uVar2,(char *)(param_1 + 0x268));
    if (iVar3 == 0) {
      FUN_00505660(*(undefined4 *)(param_1 + 0x10));
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
  }
  return;
}


