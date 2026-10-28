void FUN_00485070(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  int iVar7;
  
  iVar2 = FUN_00484400(0x600);
  uVar1 = *(ushort *)(param_1 + 6);
  uVar5 = (uVar1 & 2 | 0xc) >> 1;
  if ((uVar1 & 4) != 0) {
    FUN_00485230(iVar2,0x100);
  }
  FUN_00485230(iVar2 + 0x400,0x40);
  FUN_00485230(iVar2 + 0x500,0x40);
  iVar3 = FUN_00484560(1);
  if (iVar3 == 0xffff) {
LAB_00485211:
    FUN_005089fd(iVar2);
    return;
  }
  do {
    if (iVar3 == 0) {
      uVar4 = FUN_00484560(uVar5);
      if ((uVar4 == 0xffff) || (iVar3 = FUN_00485350(iVar2 + 0x500), iVar3 == 0xffff))
      goto LAB_00485211;
      uVar4 = (iVar3 << (sbyte)uVar5 | uVar4) + 1;
      iVar3 = FUN_00485350(iVar2 + 0x400);
      if (iVar3 == 0xffff) goto LAB_00485211;
      if (iVar3 == 0x3f) {
        iVar3 = FUN_00484560(8);
        if (iVar3 == 0xffff) goto LAB_00485211;
        iVar3 = iVar3 + 0x3f;
      }
      iVar3 = iVar3 + ((uVar1 & 4) != 0) + 2;
      if ((uint)(DAT_00665910 - (int)DAT_0066590c) < uVar4) {
        iVar7 = DAT_00665908 - uVar4;
      }
      else {
        iVar7 = -uVar4;
      }
      puVar6 = (undefined1 *)(DAT_00665910 + iVar7);
      for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        FUN_004846b0(*puVar6);
        puVar6 = puVar6 + 1;
        if (DAT_00665914 <= puVar6) {
          puVar6 = DAT_0066590c;
        }
      }
    }
    else {
      if ((uVar1 & 4) == 0) {
        iVar3 = FUN_00484560(8);
      }
      else {
        iVar3 = FUN_00485350(iVar2);
      }
      if (iVar3 == 0xffff) goto LAB_00485211;
      FUN_004846b0(iVar3);
    }
    iVar3 = FUN_00484560(1);
    if (iVar3 == 0xffff) {
      FUN_005089fd(iVar2);
      return;
    }
  } while( true );
}


