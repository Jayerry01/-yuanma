void FUN_00483ea0(int param_1,int param_2,undefined1 *param_3,int param_4,undefined1 *param_5,
                 int param_6)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar1 = param_3;
  if (0 < param_2) {
    param_3 = (undefined1 *)param_2;
    do {
      puVar2 = param_5;
      iVar3 = param_1;
      if (0 < param_1) {
        do {
          param_5 = puVar2 + 4;
          *puVar1 = puVar2[2];
          puVar1[1] = puVar2[1];
          puVar1[2] = *puVar2;
          puVar1[3] = puVar2[3];
          puVar1 = puVar1 + 4;
          iVar3 = iVar3 + -1;
          puVar2 = param_5;
        } while (iVar3 != 0);
      }
      puVar1 = puVar1 + param_4 + param_1 * -4;
      param_5 = param_5 + param_6 + param_1 * -4;
      param_3 = (undefined1 *)((int)param_3 + -1);
    } while (param_3 != (undefined1 *)0x0);
  }
  return;
}


