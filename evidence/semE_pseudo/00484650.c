void FUN_00484650(uint param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined1 *puVar4;
  
  while (param_1 != 0) {
    uVar3 = param_1;
    if (0x4000 < param_1) {
      uVar3 = 0x4000;
    }
    DAT_006658ec = DAT_006658ec - uVar3;
    param_1 = param_1 - uVar3;
    puVar2 = DAT_00665900 + uVar3;
    puVar4 = DAT_00665900;
    for (; DAT_00665900 = puVar2, uVar3 != 0; uVar3 = uVar3 - 1) {
      uVar1 = *puVar4;
      puVar4 = puVar4 + 1;
      FUN_004846b0(uVar1);
      puVar2 = DAT_00665900;
    }
  }
  return;
}


