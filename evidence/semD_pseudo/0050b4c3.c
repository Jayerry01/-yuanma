LPVOID FUN_0050b4c3(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint _Size;
  LPVOID local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_005ac4e8;
  puStack_10 = &LAB_0050a518;
  local_14 = ExceptionList;
  uVar2 = param_1 * param_2;
  uVar3 = uVar2;
  ExceptionList = &local_14;
  if (uVar2 < 0xffffffe1) {
    if (uVar2 == 0) {
      uVar3 = 1;
    }
    uVar3 = uVar3 + 0xf & 0xfffffff0;
    ExceptionList = &local_14;
  }
  do {
    local_24 = (LPVOID)0x0;
    if (uVar3 < 0xffffffe1) {
      if (DAT_007f1d70 == 3) {
        if (uVar2 <= DAT_007f1d68) {
          FUN_0050dd18(9);
          local_8 = 0;
          local_24 = (LPVOID)FUN_0050ce77(uVar2);
          local_8 = 0xffffffff;
          FUN_0050b55c();
          _Size = uVar2;
          if (local_24 == (void *)0x0) goto LAB_0050b5b0;
LAB_0050b59f:
          _memset(local_24,0,_Size);
        }
LAB_0050b5ab:
        if (local_24 != (LPVOID)0x0) {
          ExceptionList = local_14;
          return local_24;
        }
      }
      else {
        if ((DAT_007f1d70 != 2) || (DAT_005ccbec < uVar3)) goto LAB_0050b5ab;
        FUN_0050dd18(9);
        local_8 = 1;
        local_24 = (LPVOID)FUN_0050d91a(uVar3 >> 4);
        local_8 = 0xffffffff;
        FUN_0050b5e5();
        _Size = uVar3;
        if (local_24 != (void *)0x0) goto LAB_0050b59f;
      }
LAB_0050b5b0:
      local_24 = HeapAlloc(DAT_007f1d6c,8,uVar3);
    }
    if (local_24 != (LPVOID)0x0) {
      ExceptionList = local_14;
      return local_24;
    }
    if (DAT_00667714 == 0) {
      ExceptionList = local_14;
      return (LPVOID)0x0;
    }
    iVar1 = FUN_0050f884(uVar3);
    if (iVar1 == 0) {
      ExceptionList = local_14;
      return (LPVOID)0x0;
    }
  } while( true );
}


