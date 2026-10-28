void FUN_00543e90(int param_1,int param_2,int param_3,int *param_4,int param_5)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = *(int *)(param_1 + 0x24);
  iVar3 = *(int *)(param_1 + 0x5c);
  if (-1 < param_5 + -1) {
    param_3 = param_3 * 4;
    param_1 = param_5;
    do {
      iVar6 = 0;
      if (0 < iVar2) {
        do {
          puVar5 = *(undefined1 **)(param_3 + *(int *)(param_2 + iVar6 * 4));
          puVar4 = (undefined1 *)(*param_4 + iVar6);
          for (iVar7 = iVar3; iVar7 != 0; iVar7 = iVar7 + -1) {
            uVar1 = *puVar5;
            puVar5 = puVar5 + 1;
            *puVar4 = uVar1;
            puVar4 = puVar4 + iVar2;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar2);
      }
      param_3 = param_3 + 4;
      param_4 = param_4 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


