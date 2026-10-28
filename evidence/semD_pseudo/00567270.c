int * __thiscall FUN_00567270(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *local_c;
  int local_8;
  undefined1 local_4 [4];
  
  if (param_1 != param_2) {
    piVar1 = (int *)*param_1;
    puVar2 = (undefined4 *)*param_2;
    local_c = (undefined4 *)*piVar1;
    puVar7 = (undefined4 *)*puVar2;
    while (local_8 = (int)piVar1, local_c != piVar1) {
      if (puVar7 == puVar2) goto LAB_005672bc;
      puVar6 = (undefined4 *)*puVar7;
      local_c[2] = puVar7[2];
      local_c = (undefined4 *)*local_c;
      puVar7 = puVar6;
    }
    if (puVar7 == puVar2) {
LAB_005672bc:
      FUN_0049a680(&local_c);
      if (param_2 != piVar1) {
        do {
          piVar3 = (int *)*param_2;
          piVar4 = (int *)param_2[1];
          iVar5 = *param_2;
          *piVar4 = iVar5;
          *(int **)(iVar5 + 4) = piVar4;
          FUN_00402e90(param_2,0xc);
          param_2 = piVar3;
        } while (piVar3 != piVar1);
        return param_1;
      }
    }
    else {
      FUN_0049a680(&local_8);
      do {
        FUN_0049a680(local_4);
        puVar6 = (undefined4 *)FUN_0047bf10(puVar7 + 2);
        *puVar6 = param_2;
        puVar6[1] = param_2[1];
        *(undefined4 **)param_2[1] = puVar6;
        param_2[1] = (int)puVar6;
        puVar7 = (undefined4 *)*puVar7;
      } while (puVar7 != puVar2);
    }
  }
  return param_1;
}


