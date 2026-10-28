void FUN_0041f900(int param_1,int param_2,uint param_3,int param_4,undefined4 param_5)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (DAT_007eabe0 == 0x10) {
    iVar3 = 0;
    if (0 < param_4) {
      do {
        if (0 < (int)param_3) {
          uVar1 = (undefined2)param_5;
          puVar4 = (undefined4 *)((iVar3 + param_2) * DAT_007e28b0 + param_1 * 2 + DAT_007e2c88);
          for (uVar2 = param_3 >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar4 = CONCAT22(uVar1,uVar1);
            puVar4 = puVar4 + 1;
          }
          for (uVar2 = (uint)((param_3 & 1) != 0); uVar2 != 0; uVar2 = uVar2 - 1) {
            *(undefined2 *)puVar4 = uVar1;
            puVar4 = (undefined4 *)((int)puVar4 + 2);
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_4);
    }
  }
  else {
    iVar3 = 0;
    if (0 < param_4) {
      do {
        puVar4 = (undefined4 *)((iVar3 + param_2) * DAT_007e28b0 + param_1 * 4 + DAT_007e2c88);
        uVar2 = param_3;
        if (0 < (int)param_3) {
          for (; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar4 = param_5;
            puVar4 = puVar4 + 1;
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_4);
    }
  }
  DAT_007e270c = param_1 + -1 + param_3;
  DAT_007e2708 = param_2 + -1 + param_4;
  return;
}


