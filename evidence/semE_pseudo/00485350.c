uint FUN_00485350(byte *param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar3 = 0;
  iVar1 = FUN_00484560(1);
  do {
    if (iVar1 == 0xffff) {
      return 0xffffffff;
    }
    bVar2 = (byte)uVar4;
    uVar4 = uVar4 + 1;
    uVar3 = uVar3 | iVar1 << (bVar2 & 0x1f);
    bVar2 = *param_1;
    while (bVar2 <= uVar4) {
      if ((bVar2 == uVar4) && (*(ushort *)(param_1 + 2) == uVar3)) {
        return (uint)param_1[1];
      }
      param_1 = param_1 + 4;
      bVar2 = *param_1;
    }
    iVar1 = FUN_00484560(1);
  } while( true );
}


