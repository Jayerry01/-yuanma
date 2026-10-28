void FUN_0041a400(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if ((param_2 != 0) || (param_3 != 0)) {
    local_10 = *(int *)(param_1 + 4);
    local_c = *(int *)(param_1 + 8);
    local_8 = *(int *)(param_1 + 0xc) + local_10;
    local_4 = *(int *)(param_1 + 0x10) + local_c;
    bVar3 = param_2 != 0;
    if (param_3 != 0) {
      bVar3 = bVar3 | 2;
    }
    (**(code **)(**(int **)(param_1 + 0x30) + 0x50))
              (*(int **)(param_1 + 0x30),1,&local_10,bVar3,*(undefined4 *)(param_1 + 0x2c),
               0x3f800000,0);
    iVar2 = 0;
    piVar1 = (int *)(param_1 + 0x98);
    do {
      if (*piVar1 != 0) {
        FUN_0041ae90(param_1,iVar2);
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 0xc);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
