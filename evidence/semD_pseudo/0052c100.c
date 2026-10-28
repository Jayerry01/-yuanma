void FUN_0052c100(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  if ((0 < (int)param_1) && (puVar3 = DAT_00723270, DAT_00723264 != 0)) {
    do {
      uVar1 = *(uint *)(param_2 + uVar4 * 4);
      if ((uVar1 != 0) && ((uVar1 < DAT_00723268 && (puVar3[uVar1] != 0)))) {
        if (uVar1 == DAT_0072326c) {
          DAT_0072329c = *puVar3;
          DAT_0072326c = 0;
        }
        FUN_0052c1a0(puVar3[*(int *)(param_2 + uVar4 * 4)]);
        DAT_00723270[*(int *)(param_2 + uVar4 * 4)] = 0;
        puVar2 = (undefined4 *)FUN_00530d80(8);
        if (puVar2 == (undefined4 *)0x0) {
          return;
        }
        *puVar2 = *(undefined4 *)(param_2 + uVar4 * 4);
        puVar2[1] = DAT_00723274;
        puVar3 = DAT_00723270;
        DAT_00723274 = puVar2;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_1);
  }
  return;
}


