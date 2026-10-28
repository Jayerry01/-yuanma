int __thiscall FUN_004fae30(int param_1,int param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (param_2 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 8) <= *(int *)(param_1 + 4)) {
    return 0;
  }
  iVar5 = *(int *)(param_1 + 0xc);
  bVar1 = *(byte *)(iVar5 + *(int *)(param_1 + 4));
  uVar3 = (int)*(char *)(((int)(uint)bVar1 >> 3) + 0x10 + param_1) & 1 << (bVar1 & 7);
  while ((uVar3 != 0 && (*(int *)(param_1 + 4) < *(int *)(param_1 + 8)))) {
    iVar4 = *(int *)(param_1 + 4) + 1;
    *(int *)(param_1 + 4) = iVar4;
    bVar1 = *(byte *)(iVar4 + iVar5);
    uVar3 = (int)*(char *)(((int)(uint)bVar1 >> 3) + 0x10 + param_1) & 1 << (bVar1 & 7);
  }
  if (*(char *)(*(int *)(param_1 + 4) + -1 + iVar5) == '\"') {
    iVar5 = 0;
    if (0 < param_3 + -1) {
      while ((*(int *)(param_1 + 4) < *(int *)(param_1 + 8) &&
             (cVar2 = *(char *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0xc)), cVar2 != '\"'))) {
        *(char *)(iVar5 + param_2) = cVar2;
        iVar5 = iVar5 + 1;
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
        if (param_3 + -1 <= iVar5) {
          *(undefined1 *)(iVar5 + param_2) = 0;
          return iVar5;
        }
      }
    }
  }
  else {
    iVar5 = 0;
    if (0 < param_3 + -1) {
      do {
        if ((*(int *)(param_1 + 8) <= *(int *)(param_1 + 4)) ||
           (bVar1 = *(byte *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0xc)),
           ((int)*(char *)(((int)(uint)bVar1 >> 3) + 0x10 + param_1) & 1 << (bVar1 & 7)) != 0))
        break;
        *(byte *)(iVar5 + param_2) = bVar1;
        iVar5 = iVar5 + 1;
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
      } while (iVar5 < param_3 + -1);
    }
  }
  *(undefined1 *)(iVar5 + param_2) = 0;
  return iVar5;
}


