int __thiscall FUN_00554030(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = FUN_00553860(param_3);
  iVar2 = iVar2 + 0x578;
  uVar3 = FUN_00553880(iVar2);
  iVar2 = FUN_00554820(uVar3,iVar2,param_3);
  if (0 < iVar2) {
    iVar4 = FUN_00553870();
    if (iVar2 != iVar4) {
      return -1;
    }
    if ((*(byte *)(param_2 + 5) & 0x10) != 0) {
      cVar1 = FUN_00553a80(*(undefined4 *)(param_1 + 0x14));
      if (cVar1 == '\0') {
        return -1;
      }
    }
    if ((*(byte *)(param_2 + 5) & 8) != 0) {
      cVar1 = FUN_005539d0();
      if (cVar1 == '\0') {
        return -1;
      }
    }
    if ((*(byte *)(param_2 + 5) & 0x40) != 0) {
      cVar1 = FUN_00553b20();
      if (cVar1 == '\0') {
        return -1;
      }
    }
    if (0x578 < *(ushort *)(param_2 + 0xc)) {
      return -1;
    }
  }
  return iVar2;
}


