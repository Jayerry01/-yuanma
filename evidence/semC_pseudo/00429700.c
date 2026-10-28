uint FUN_00429700(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  uVar3 = 0;
  puVar4 = &DAT_007dff60;
  for (iVar2 = 0xff; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  _DAT_007dff40 = 0;
  if (DAT_005c6798 != 0) {
    uVar3 = thunk_FUN_004329c0();
  }
  uVar1 = FUN_00432250();
  uVar3 = uVar3 & uVar1;
  iVar2 = thunk_FUN_004325f0(2,0xac44,0x10);
  if (iVar2 != 0) {
    return uVar3;
  }
  iVar2 = thunk_FUN_004325f0(2,0xac44,8);
  if (iVar2 != 0) {
    return uVar3;
  }
  iVar2 = thunk_FUN_004325f0(1,0xac44,0x10);
  if (iVar2 != 0) {
    return uVar3;
  }
  iVar2 = thunk_FUN_004325f0(1,0xac44,8);
  if (iVar2 != 0) {
    return uVar3;
  }
  iVar2 = thunk_FUN_004325f0(2,0x5622,0x10);
  if (iVar2 != 0) {
    return uVar3;
  }
  iVar2 = thunk_FUN_004325f0(2,0x5622,8);
  if (iVar2 != 0) {
    return uVar3;
  }
  iVar2 = thunk_FUN_004325f0(1,0x5622,0x10);
  if (iVar2 != 0) {
    return uVar3;
  }
  iVar2 = thunk_FUN_004325f0(1,0x5622,8);
  if (iVar2 != 0) {
    return uVar3;
  }
  iVar2 = thunk_FUN_004325f0(2,0x2b11,0x10);
  if (iVar2 != 0) {
    return uVar3;
  }
  iVar2 = thunk_FUN_004325f0(2,0x2b11,8);
  if (iVar2 != 0) {
    return uVar3;
  }
  iVar2 = thunk_FUN_004325f0(1,0x2b11,0x10);
  if (iVar2 != 0) {
    return uVar3;
  }
  iVar2 = thunk_FUN_004325f0(1,0x2b11,8);
  return -(uint)(iVar2 != 0) & uVar3;
}


