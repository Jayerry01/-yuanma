undefined4 FUN_00484cb0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  int iVar7;
  
  while( true ) {
    while( true ) {
      iVar3 = FUN_00484590(param_3);
      iVar7 = param_1 + iVar3 * 6;
      bVar2 = *(byte *)(param_1 + iVar3 * 6);
      while (uVar5 = (uint)bVar2, 0x10 < uVar5) {
        if (uVar5 == 99) {
          return 1;
        }
        FUN_00484560(*(undefined1 *)(iVar7 + 1));
        iVar3 = FUN_00484590(uVar5 - 0x10);
        piVar1 = (int *)(iVar7 + 2);
        iVar7 = *piVar1 + iVar3 * 6;
        bVar2 = *(byte *)(*piVar1 + iVar3 * 6);
      }
      FUN_00484560(*(undefined1 *)(iVar7 + 1));
      if (uVar5 != 0x10) break;
      FUN_004846b0(*(undefined1 *)(iVar7 + 2));
    }
    if (uVar5 == 0xf) break;
    iVar3 = FUN_00484560(uVar5);
    iVar3 = iVar3 + *(int *)(iVar7 + 2);
    iVar4 = FUN_00484590(param_4);
    iVar7 = param_2 + iVar4 * 6;
    bVar2 = *(byte *)(param_2 + iVar4 * 6);
    while (uVar5 = (uint)bVar2, 0x10 < uVar5) {
      if (uVar5 == 99) {
        return 1;
      }
      FUN_00484560(*(undefined1 *)(iVar7 + 1));
      iVar4 = FUN_00484590(uVar5 - 0x10);
      piVar1 = (int *)(iVar7 + 2);
      iVar7 = *piVar1 + iVar4 * 6;
      bVar2 = *(byte *)(*piVar1 + iVar4 * 6);
    }
    FUN_00484560(*(undefined1 *)(iVar7 + 1));
    iVar4 = FUN_00484560(uVar5);
    uVar5 = iVar4 + *(int *)(iVar7 + 2);
    if ((uint)(DAT_00665910 - (int)DAT_0066590c) < uVar5) {
      iVar7 = DAT_00665908 - uVar5;
    }
    else {
      iVar7 = -uVar5;
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
  return 0;
}


