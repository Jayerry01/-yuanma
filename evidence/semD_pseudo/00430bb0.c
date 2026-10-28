int FUN_00430bb0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  if ((param_1 <= param_3) && (param_3 <= param_2)) {
    uVar1 = _rand();
    uVar1 = uVar1 & 0x80000003;
    bVar4 = uVar1 == 0;
    if ((int)uVar1 < 0) {
      bVar4 = (uVar1 - 1 | 0xfffffffc) == 0xffffffff;
    }
    if (!bVar4) {
      return param_3;
    }
  }
  iVar2 = _rand();
  iVar2 = iVar2 % 0x14 + 1;
  if (0 < iVar2) {
    do {
      iVar3 = _rand();
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    return iVar3 % ((param_2 - param_1) + 1) + param_1;
  }
  return param_3 + param_1;
}


