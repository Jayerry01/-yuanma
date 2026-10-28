undefined4 * __thiscall FUN_004e8c00(undefined4 *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = param_1;
  for (iVar2 = 0x23; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    *param_1 = 1;
    iVar2 = 4 - (int)param_2;
    do {
      cVar1 = *param_2;
      param_2[(int)param_1 + iVar2] = cVar1;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
    FUN_004e8c50();
  }
  return param_1;
}



void __fastcall thunk_FUN_004ea660(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (*(int *)(param_1 + 0x80) != 0) {
    FUN_005089fd(*(undefined4 *)(param_1 + 0x84));
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  if (*(int *)(param_1 + 0x68) != 0) {
    FUN_005089fd(*(undefined4 *)(param_1 + 0x50));
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  if (*(int *)(param_1 + 0x70) != 0) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 100)) {
      iVar4 = 0;
      do {
        FUN_0040bbe0(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x10 + iVar4));
        FUN_005089fd(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x28 + iVar4));
        iVar1 = iVar1 + 1;
        iVar4 = iVar4 + 0x2c;
      } while (iVar1 < *(int *)(param_1 + 100));
    }
    if (0 < *(int *)(param_1 + 0x6c)) {
      iVar1 = 0;
      do {
        if (*(int *)(param_1 + 0x44) == 0) {
          iVar4 = *(int *)(param_1 + 0x4c) + iVar1;
          FUN_0040bb90(*(undefined4 *)(iVar4 + 0x10),**(undefined4 **)(iVar4 + 0x28));
        }
        FUN_0040bbe0(*(undefined4 *)(*(int *)(param_1 + 0x4c) + 0x10 + iVar1));
        FUN_005089fd(*(undefined4 *)(*(int *)(param_1 + 0x4c) + 0x24 + iVar1));
        iVar4 = *(int *)(param_1 + 0x4c);
        uVar2 = (uint)(*(int *)(param_1 + 0x44) == 0);
        if ((int)uVar2 < *(int *)(iVar4 + 0x14 + iVar1)) {
          do {
            FUN_005089fd(*(undefined4 *)(*(int *)(iVar4 + iVar1 + 0x28) + uVar2 * 4));
            iVar4 = *(int *)(param_1 + 0x4c);
            uVar2 = uVar2 + 1;
          } while ((int)uVar2 < *(int *)(iVar4 + 0x14 + iVar1));
        }
        FUN_005089fd(*(undefined4 *)(*(int *)(param_1 + 0x4c) + 0x28 + iVar1));
        iVar3 = iVar3 + 1;
        iVar1 = iVar1 + 0x2c;
      } while (iVar3 < *(int *)(param_1 + 0x6c));
    }
    FUN_005089fd(*(undefined4 *)(param_1 + 0x74));
  }
  *(undefined4 *)(param_1 + 0x70) = 0;
  if (*(int *)(param_1 + 100) != 0) {
    FUN_005089fd(*(undefined4 *)(param_1 + 0x48));
    *(undefined4 *)(param_1 + 100) = 0;
  }
  if (*(int *)(param_1 + 0x6c) != 0) {
    FUN_005089fd(*(undefined4 *)(param_1 + 0x4c));
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  if (*(int *)(param_1 + 0x80) != 0) {
    FUN_005089fd(*(undefined4 *)(param_1 + 0x84));
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  if (*(int *)(param_1 + 0x78) != 0) {
    FUN_005089fd(*(int *)(param_1 + 0x78));
    *(undefined4 *)(param_1 + 0x78) = 0;
  }
  if (*(int *)(param_1 + 0x7c) != 0) {
    FUN_0040bbe0(*(int *)(param_1 + 0x7c));
  }
  return;
}


