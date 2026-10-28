int FUN_0056a040(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 1;
  cVar1 = *(char *)(*(int *)(param_1 + 8) + 0x11);
  if ((cVar1 != '\x01') || (*(char *)(*(int *)(param_2 + 8) + 0x11) != '\0')) {
    if ((cVar1 == '\0') && (*(char *)(*(int *)(param_2 + 8) + 0x11) == '\x01')) {
      return -1;
    }
    if (*(int *)(*(int *)(param_1 + 8) + 4) == 1) {
      if (*(int *)(*(int *)(param_2 + 8) + 4) != 1) {
        return 1;
      }
    }
    else if (*(int *)(*(int *)(param_2 + 8) + 4) == 1) {
      return -1;
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 4);
    iVar3 = *(int *)(*(int *)(param_2 + 0xc) + 4);
    if (iVar2 <= iVar3) {
      iVar4 = (iVar3 <= iVar2) - 1;
    }
  }
  return iVar4;
}


