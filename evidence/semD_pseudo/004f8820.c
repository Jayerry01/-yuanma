void FUN_004f8820(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_2;
  while( true ) {
    iVar2 = iVar3 * 2;
    iVar1 = iVar2 + 2;
    if (param_3 <= iVar1) break;
    if (*(float *)(*(int *)(param_1 + -4 + iVar1 * 4) + 0xc) <
        *(float *)(*(int *)(param_1 + iVar1 * 4) + 0xc)) {
      iVar1 = iVar2 + 1;
    }
    *(undefined4 *)(param_1 + iVar3 * 4) = *(undefined4 *)(param_1 + iVar1 * 4);
    iVar3 = iVar1;
  }
  if (iVar1 == param_3) {
    *(undefined4 *)(param_1 + iVar3 * 4) = *(undefined4 *)(param_1 + -4 + iVar1 * 4);
    iVar3 = iVar2 + 1;
  }
  if (iVar3 <= param_2) {
    *(int *)(param_1 + iVar3 * 4) = param_4;
    return;
  }
  do {
    iVar2 = (iVar3 + -1) / 2;
    iVar1 = *(int *)(param_1 + iVar2 * 4);
    if (*(float *)(iVar1 + 0xc) <= *(float *)(param_4 + 0xc)) break;
    *(int *)(param_1 + iVar3 * 4) = iVar1;
    iVar3 = iVar2;
  } while (param_2 < iVar2);
  *(int *)(param_1 + iVar3 * 4) = param_4;
  return;
}


