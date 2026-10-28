int __fastcall FUN_00561d10(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = __ftol();
  iVar3 = __ftol();
  iVar4 = __ftol();
  iVar1 = *(int *)(param_1 + 0x4a0);
  if (iVar1 <= iVar2) {
    iVar2 = iVar1 + -1;
  }
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (*(int *)(param_1 + 0x4a4) <= iVar3) {
    iVar3 = *(int *)(param_1 + 0x4a4) + -1;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (*(int *)(param_1 + 0x4a8) <= iVar4) {
    iVar4 = *(int *)(param_1 + 0x4a8) + -1;
  }
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  return iVar1 * iVar3 + iVar2 + *(int *)(param_1 + 0x4ac) * iVar4;
}


