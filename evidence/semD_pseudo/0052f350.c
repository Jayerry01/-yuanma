undefined4 FUN_0052f350(void)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar2 = FUN_0052bc40(0xdf1);
  uVar4 = 0;
  if (uVar2 != 0) {
    do {
      uVar3 = FUN_0052c460();
      FUN_0052c070(uVar3);
      uVar4 = uVar4 + 1;
      cVar1 = FUN_0052c320(uVar4);
      if (cVar1 == '\0') {
        return 0;
      }
      cVar1 = FUN_0052f270();
      if (cVar1 == '\0') {
        return 0;
      }
    } while (uVar4 < uVar2);
  }
  uVar2 = FUN_0052bc40(0xdf2);
  uVar4 = 0;
  if (uVar2 != 0) {
    do {
      uVar3 = FUN_0052c460();
      FUN_0052c070(uVar3);
      uVar4 = uVar4 + 1;
      cVar1 = FUN_0052c280(uVar4);
      if (cVar1 == '\0') {
        return 0;
      }
      cVar1 = FUN_0052f270();
      if (cVar1 == '\0') {
        return 0;
      }
    } while (uVar4 < uVar2);
  }
  uVar2 = FUN_0052bc40(0xdf3);
  uVar4 = 0;
  if (uVar2 != 0) {
    do {
      uVar3 = FUN_0052c460();
      FUN_0052c070(uVar3);
      uVar4 = uVar4 + 1;
      cVar1 = FUN_0052c3c0(uVar4);
      if (cVar1 == '\0') {
        return 0;
      }
      cVar1 = FUN_0052f270();
      if (cVar1 == '\0') {
        return 0;
      }
    } while (uVar4 < uVar2);
  }
  uVar3 = FUN_0052c460();
  FUN_0052c070(uVar3);
  FUN_0052f270();
  return 1;
}


