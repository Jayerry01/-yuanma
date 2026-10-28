undefined4 FUN_005952af(int *param_1,int *param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_4 == param_1[6]) {
    param_1[2] = *param_2;
    param_1[3] = param_2[1];
    param_1[4] = param_2[param_4 * 2 + -2];
    param_1[5] = param_2[param_4 * 2 + -1];
    uVar1 = (**(code **)(*param_1 + 0xc))(param_1[7],param_2,param_3,param_4);
  }
  else {
    FUN_00596780(s_data_must_match_size_of_interpol_005d3a30,
                 s_E__ftp_gsl_1_0_interpolation_int_005d3a08,0x49,4);
    uVar1 = 4;
  }
  return uVar1;
}


