void __fastcall FUN_005081e1(int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_00508015(iVar1 + 0x34);
  }
  iVar1 = FUN_00508919();
  while (iVar1 != -1) {
    iVar1 = FUN_0050be69(iVar1);
    if (iVar1 == 0) goto LAB_0050823f;
    iVar1 = FUN_005088cd();
  }
  FUN_00507a43(*(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 1);
LAB_0050823f:
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 4 + (int)param_1);
  if (*(int *)(iVar1 + 0x30) < 0) {
    FUN_00508020(iVar1 + 0x34);
  }
  return;
}


