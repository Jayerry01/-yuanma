void FUN_00484460(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (DAT_00665910 != DAT_0066590c) {
    uVar1 = (int)DAT_00665910 - (int)DAT_0066590c;
    puVar3 = DAT_0066590c;
    puVar4 = DAT_0066591c;
    for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    DAT_0066591c = (undefined4 *)((int)DAT_0066591c + ((int)DAT_00665910 - (int)DAT_0066590c));
  }
  return;
}


