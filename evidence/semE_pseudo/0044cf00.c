void __fastcall FUN_0044cf00(int *param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  pcVar1 = (char *)*param_1;
  if ((*pcVar1 == '\0') && (*(char **)(*(int *)(pcVar1 + 4) + 4) == pcVar1)) {
    *param_1 = *(int *)(pcVar1 + 0xc);
    return;
  }
  iVar3 = *(int *)(pcVar1 + 8);
  if (iVar3 == 0) {
    iVar3 = *(int *)(pcVar1 + 4);
    if (pcVar1 == *(char **)(iVar3 + 8)) {
      do {
        *param_1 = iVar3;
        iVar3 = *(int *)(iVar3 + 4);
      } while (*param_1 == *(int *)(iVar3 + 8));
    }
    *param_1 = iVar3;
    return;
  }
  for (iVar2 = *(int *)(iVar3 + 0xc); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
    iVar3 = iVar2;
  }
  *param_1 = iVar3;
  return;
}


