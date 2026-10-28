FUN_005962e6(undefined4 *param_1,int param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,int param_7,double *param_8)

{
  undefined4 uVar1;
  double local_5c;
  double local_54;
  double local_4c;
  undefined1 local_44 [8];
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  double local_2c;
  int local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 *local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_10 = param_1;
  if (param_7 == 0) {
    local_20 = FUN_00595770(param_2,param_5,param_6,0,param_4 + -1);
  }
  else {
    local_20 = FUN_005957d0(param_7,param_2,param_4,param_5,param_6);
  }
  local_c = *(undefined4 *)(param_2 + 8 + local_20 * 8);
  uStack_8 = *(undefined4 *)(param_2 + 0xc + local_20 * 8);
  local_1c = *(undefined4 *)(param_2 + local_20 * 8);
  uStack_18 = *(undefined4 *)(param_2 + 4 + local_20 * 8);
  local_2c = (double)CONCAT44(uStack_8,local_c) - (double)CONCAT44(uStack_18,local_1c);
  if (local_2c <= 0.0) {
    *(undefined4 *)param_8 = 0;
    *(undefined4 *)((int)param_8 + 4) = 0;
    uVar1 = 0xffffffff;
  }
  else {
    local_3c = *(undefined4 *)(param_3 + local_20 * 8);
    uStack_38 = *(undefined4 *)(param_3 + 4 + local_20 * 8);
    local_34 = *(undefined4 *)(param_3 + 8 + local_20 * 8);
    uStack_30 = *(undefined4 *)(param_3 + 0xc + local_20 * 8);
    local_4c = (double)CONCAT44(param_6,param_5) - (double)CONCAT44(uStack_18,local_1c);
    FUN_00596135(*local_10,
                 (double)CONCAT44(uStack_30,local_34) - (double)CONCAT44(uStack_38,local_3c),
                 local_2c,local_20,local_44,&local_5c,&local_54);
    *param_8 = local_54 * 6.0 * local_4c + local_5c * 2.0;
    uVar1 = 0;
  }
  return uVar1;
}



undefined4