undefined1 FUN_0053a390(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 *puStack_60;
  undefined1 local_38 [26];
  short local_1e;
  int local_1a;
  
  if (DAT_0072329c == 0) {
    puStack_60 = (undefined1 *)0x506;
    FUN_00530d00();
    return 0;
  }
  puStack_60 = local_38;
  FUN_0053a1a0();
  cVar1 = FUN_0053a250(local_38);
  if (cVar1 == '\0') {
    puStack_60 = (undefined1 *)0x1;
    (*DAT_007dc854)(0xffffffca);
    FUN_0053a1c0(&puStack_60);
    cVar1 = FUN_0053a2a0(&puStack_60);
    if (cVar1 == '\0') {
      FUN_00530d00(0x508);
      return 0;
    }
    uVar2 = FUN_0053b040(&puStack_60);
    return uVar2;
  }
  if (local_1e != 1) {
    puStack_60 = (undefined1 *)0x508;
    FUN_00530d00();
    return 0;
  }
  if (local_1a != 0) {
    if (local_1a == 1) {
      puStack_60 = local_38;
      uVar2 = FUN_0053ab70();
      puStack_60 = (undefined1 *)0x53a479;
      FUN_0052f350();
      return uVar2;
    }
    if (local_1a != 2) {
      puStack_60 = (undefined1 *)0x508;
      FUN_00530d00();
      return 0;
    }
    puStack_60 = local_38;
    uVar2 = FUN_0053add0();
    puStack_60 = (undefined1 *)0x53a45e;
    FUN_0052f350();
    return uVar2;
  }
  puStack_60 = local_38;
  uVar2 = FUN_0053a4a0();
  puStack_60 = (undefined1 *)0x53a494;
  FUN_0052f350();
  return uVar2;
}


