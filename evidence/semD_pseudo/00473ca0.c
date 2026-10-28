undefined4 FUN_00473ca0(void)

{
  int iVar1;
  int *piStack_5c;
  undefined4 uStack_58;
  undefined1 *puStack_54;
  int *piStack_50;
  undefined1 *puStack_4c;
  undefined *puStack_48;
  int *apiStack_44 [17];
  
  apiStack_44[0] = DAT_005e0370;
  puStack_48 = (undefined *)0x473cae;
  iVar1 = (**(code **)(*DAT_005e0370 + 0x28))();
  if (iVar1 == 0) {
    puStack_48 = &DAT_005e0334;
    puStack_4c = (undefined1 *)0x473cbc;
    FUN_00473a20();
    piStack_50 = (int *)0x473cc6;
    puStack_4c = (undefined1 *)apiStack_44;
    FUN_00430c40();
    puStack_4c = (undefined1 *)0x3;
    piStack_50 = DAT_005e0370;
    puStack_54 = (undefined1 *)0x473cdb;
    puStack_48 = (undefined *)apiStack_44;
    (**(code **)(*DAT_005e0370 + 100))();
    uStack_58 = 2;
    piStack_5c = DAT_005e0370;
    puStack_54 = (undefined1 *)&piStack_50;
    (**(code **)(*DAT_005e0370 + 100))();
    (**(code **)(*DAT_005e0370 + 100))(DAT_005e0370,1,&piStack_5c);
    return 1;
  }
  return 0;
}


