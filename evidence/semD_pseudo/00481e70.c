FUN_00481e70(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if ((((iVar1 != 0) && (-1 < param_2)) && (param_2 < *(int *)(param_1 + 0x4c))) &&
     (iVar2 = *(int *)(param_1 + 0x24), iVar2 != -1)) {
    if (param_5 < 1) {
      iVar2 = *(int *)(param_1 + 0x10) * param_2 + iVar2;
    }
    else {
      iVar2 = iVar2 + *(int *)(param_1 + 0x10) * param_2 +
              *(int *)(param_1 + 0x28 + param_5 * 4) * 4;
    }
    *param_3 = *(undefined4 *)(iVar2 + iVar1);
    *param_4 = *(undefined4 *)(iVar2 + iVar1 + 4);
    return 1;
  }
  return 0;
}


