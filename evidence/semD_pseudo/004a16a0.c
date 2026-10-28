void __thiscall FUN_004a16a0(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int **ppiVar3;
  int *local_4;
  
  piVar1 = param_2;
  local_4 = param_1;
  if (((uint)param_2 & 0xffff) == 8) {
    if (param_1[4] != param_1[5]) {
      *(undefined1 *)(param_1[5] + -1) = 0;
      param_1[5] = param_1[5] + -1;
      if (param_1[4] != param_1[5]) {
        param_2 = (int *)CONCAT31(param_2._1_3_,*(undefined1 *)(param_1[5] + -1));
        iVar2 = FUN_00549c40(param_2);
        if (iVar2 != 0) {
          *(undefined1 *)(param_1[5] + -1) = 0;
          param_1[5] = param_1[5] + -1;
        }
      }
    }
  }
  else {
    if (((uint)param_2 & 0xffff) != 0xd) {
      if (param_1[5] + 1 == param_1[6]) {
        param_2 = (int *)0x1;
        local_4 = (int *)(param_1[5] - param_1[4]);
        ppiVar3 = &param_2;
        if (local_4 != (int *)0x0) {
          ppiVar3 = &local_4;
        }
        FUN_0049be40((int)*ppiVar3 + (int)local_4);
      }
      FUN_00402bc0(param_1[5] + 1);
      *(char *)param_1[5] = (char)piVar1;
      param_1[5] = param_1[5] + 1;
      return;
    }
    (**(code **)(*param_1 + 0xc))(param_1[0xc],param_1[4],param_1[5] - param_1[4]);
    if ((undefined1 *)param_1[4] != (undefined1 *)param_1[5]) {
      *(undefined1 *)param_1[4] = 0;
      param_1[5] = param_1[4];
      return;
    }
  }
  return;
}


