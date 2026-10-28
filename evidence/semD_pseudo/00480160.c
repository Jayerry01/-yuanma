undefined4 FUN_00480160(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  
  iVar3 = 0;
  puVar4 = &DAT_005c8198;
  do {
    uVar1 = FUN_00480220(param_1[7]);
    if (puVar4[-1] == (uVar1 & 0xffff)) {
      uVar1 = FUN_00480220(param_1[4]);
      if (*puVar4 == (uVar1 & 0xffff)) {
        uVar1 = FUN_00480220(param_1[5]);
        if (puVar4[1] == (uVar1 & 0xffff)) {
          uVar1 = FUN_00480220(param_1[6]);
          if (puVar4[2] == (uVar1 & 0xffff)) {
            DAT_0062e678 = DAT_0062e678 + 1;
            (&DAT_005c818c)[iVar3 * 8] = 1;
            puVar5 = &DAT_0062e578 + iVar3 * 8;
            for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar5 = *param_1;
              param_1 = param_1 + 1;
              puVar5 = puVar5 + 1;
            }
            return 1;
          }
        }
      }
    }
    puVar4 = puVar4 + 8;
    iVar3 = iVar3 + 1;
  } while ((int)puVar4 < 0x5c8298);
  return 0;
}


