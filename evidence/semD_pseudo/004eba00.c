FUN_004eba00(int param_1,int param_2,int param_3,undefined4 *param_4,undefined4 *param_5)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x80)) {
    psVar2 = *(short **)(param_1 + 0x84);
    do {
      if ((*psVar2 == param_2) && (psVar2[1] == param_3)) {
        *param_4 = *(undefined4 *)(*(short **)(param_1 + 0x84) + iVar1 * 6 + 2);
        *param_5 = *(undefined4 *)(iVar1 * 0xc + 8 + *(int *)(param_1 + 0x84));
        break;
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 6;
    } while (iVar1 < *(int *)(param_1 + 0x80));
  }
  return iVar1 != *(int *)(param_1 + 0x80);
}


