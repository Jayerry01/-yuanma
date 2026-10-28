void __thiscall FUN_0055dfc0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_005a5328;
  local_c = ExceptionList;
  piVar1 = *(int **)(param_1 + 0x658);
  piVar3 = (int *)*piVar1;
  local_4 = 0;
  if (piVar3 != piVar1) {
    while (iVar2 = piVar3[2], *(int *)(iVar2 + 0x13c) != param_2) {
      piVar3 = (int *)*piVar3;
      if (piVar3 == piVar1) {
        return;
      }
    }
    ExceptionList = &local_c;
    FUN_00567220();
    FUN_00566e50(iVar2);
    FUN_0055df80(iVar2);
  }
  ExceptionList = local_c;
  return;
}


