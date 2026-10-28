void FUN_00538f00(int *param_1,undefined1 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = *param_1 + 1;
  if (iVar3 <= param_1[1]) {
    iVar4 = iVar3 * 0x21;
    do {
      iVar5 = param_1[2] + 1;
      if (iVar5 <= param_1[3]) {
        iVar2 = param_1[5];
        do {
          iVar1 = param_1[4] + 1;
          if (iVar1 <= iVar2) {
            do {
              *(undefined1 *)(param_3 + (iVar4 + iVar5) * 0x21 + iVar1) = param_2;
              iVar2 = param_1[5];
              iVar1 = iVar1 + 1;
            } while (iVar1 <= iVar2);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 <= param_1[3]);
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x21;
    } while (iVar3 <= param_1[1]);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
