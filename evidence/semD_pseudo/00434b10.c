void FUN_00434b10(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (param_1 != (int *)0x0) {
    local_10 = param_1[1] + param_2;
    local_c = param_1[2] + param_3;
    iVar1 = param_1[0xc];
    local_8 = __ftol();
    local_8 = local_8 + param_2;
    local_4 = __ftol();
    local_4 = local_4 + param_3;
    FUN_00433d10(*(undefined4 *)(*param_1 + iVar1 * 4),&local_10);
    FUN_00433ef0(*(undefined4 *)(*param_1 + iVar1 * 4),param_6,param_7,0,param_8);
  }
  return;
}


