void FUN_00419830(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = *(int *)(param_2 + 8) * 0x20;
  if (DAT_007e0eb8 < iVar2) {
    DAT_007e0eb8 = iVar2;
    DAT_007e2808 = FUN_005099a7(DAT_007e2808,iVar2);
  }
  iVar2 = *(int *)(param_2 + 0xc);
  iVar6 = 0;
  iVar5 = 0;
  if (0 < *(int *)(param_2 + 8)) {
    puVar3 = (undefined4 *)(DAT_007e2808 + 8);
    do {
      piVar1 = *(int **)(iVar2 + iVar5 * 4);
      puVar4 = puVar3;
      if (*piVar1 == 1) {
        iVar6 = iVar6 + 1;
        puVar3[-2] = piVar1[4];
        puVar4 = puVar3 + 8;
        puVar3[-1] = *(undefined4 *)(*(int *)(iVar2 + iVar5 * 4) + 0x14);
        *puVar3 = *(undefined4 *)(*(int *)(iVar2 + iVar5 * 4) + 0x18);
        puVar3[2] = *(undefined4 *)(param_2 + 0x20);
        puVar3[3] = *(undefined4 *)(param_2 + 0x20);
        puVar3[4] = 0;
        puVar3[5] = 0;
      }
      iVar5 = iVar5 + 1;
      puVar3 = puVar4;
    } while (iVar5 < *(int *)(param_2 + 8));
    if (0 < iVar6) {
      (**(code **)(*param_1 + 0x70))(param_1,1,0x1e2,DAT_007e2808,iVar6,0);
    }
  }
  return;
}


