void FUN_004846b0(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  FUN_00485810(param_1,&DAT_006658f0);
  *(char *)DAT_00665910 = (char)param_1;
  uVar2 = DAT_00665908;
  DAT_00665910 = (undefined4 *)((int)DAT_00665910 + 1);
  if (DAT_00665914 <= DAT_00665910) {
    puVar3 = DAT_0066590c;
    puVar4 = DAT_0066591c;
    for (uVar1 = DAT_00665908 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    DAT_0066591c = (undefined4 *)((int)DAT_0066591c + DAT_00665908);
    DAT_00665910 = DAT_0066590c;
  }
  return;
}


