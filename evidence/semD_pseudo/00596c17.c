undefined4 FUN_00596c17(int *param_1,int *param_2,int *param_3,int *param_4)

{
  undefined4 uVar1;
  
  if (((*param_1 == *param_3) && (*param_2 == *param_3)) && (*param_4 == *param_3)) {
    uVar1 = FUN_00596c8d(param_1[2],param_1[1],param_2[2],param_2[1],param_3[2],param_3[1],
                         param_4[2],param_4[1],*param_1);
  }
  else {
    uVar1 = 0x13;
  }
  return uVar1;
}



undefined4