undefined4 FUN_0053b5f0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  iVar2 = (*DAT_007dc850)(puVar1[7],1,0x1000);
  if (iVar2 < 1) {
    if (*(char *)(puVar1 + 8) != '\0') {
      DAT_007242f8 = 1;
    }
    *(undefined1 *)puVar1[7] = 0xff;
    *(undefined1 *)(puVar1[7] + 1) = 0xd9;
    return 0;
  }
  if (iVar2 < 0x1000) {
    FUN_00530d50();
  }
  puVar1[1] = iVar2;
  *puVar1 = puVar1[7];
  *(undefined1 *)(puVar1 + 8) = 0;
  return 1;
}


