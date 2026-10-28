void FUN_0053a1f0(void)

{
  char cVar1;
  undefined4 uStack_68;
  undefined1 *puStack_64;
  undefined4 uStack_60;
  undefined1 *puStack_5c;
  undefined1 auStack_40 [8];
  undefined1 local_38 [56];
  
  puStack_5c = local_38;
  uStack_60 = 0x53a1fd;
  FUN_0053a1a0();
  puStack_5c = (undefined1 *)0x1;
  uStack_60 = 0xffffffca;
  puStack_64 = (undefined1 *)0x53a20a;
  (*DAT_007dc854)();
  puStack_64 = auStack_40;
  uStack_68 = 0x53a214;
  cVar1 = FUN_0053a250();
  if (cVar1 == '\0') {
    uStack_68 = 0x53a225;
    puStack_64 = (undefined1 *)&uStack_60;
    FUN_0053a1c0();
    puStack_64 = (undefined1 *)0x1;
    uStack_68 = 0xffffffca;
    (*DAT_007dc854)();
    FUN_0053a2a0(&uStack_68);
  }
  return;
}


