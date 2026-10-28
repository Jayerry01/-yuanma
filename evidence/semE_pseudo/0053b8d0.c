void FUN_0053b8d0(void)

{
  char cVar1;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 local_14 [20];
  
  puStack_18 = local_14;
  uStack_1c = 0x53b8dd;
  cVar1 = FUN_0053b8b0();
  if (cVar1 == '\0') {
    return;
  }
  puStack_18 = (undefined1 *)0x1;
  uStack_1c = 0xffffffee;
  (*DAT_007dc854)();
  FUN_0053b910(&uStack_1c);
  return;
}


