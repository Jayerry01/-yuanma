int * FUN_00598ed0(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_2c [10];
  
  local_2c[5] = 0;
  local_2c[6] = 0;
  local_2c[7] = 0;
  local_2c[8] = 0;
  local_2c[9] = 0;
  if (param_4 == 0) {
    FUN_00596780(s_vector_length_n_must_be_positive_005d4ce4,
                 s_E__ftp_gsl_1_0_vector_view_sourc_005d4cc0,0x37,4);
    piVar2 = local_2c + 5;
    piVar3 = param_1;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
  }
  else if (param_3 == 0) {
    FUN_00596780(s_stride_must_be_positive_integer_005d4d34,
                 s_E__ftp_gsl_1_0_vector_view_sourc_005d4d10,0x3d,4);
    piVar2 = local_2c + 5;
    piVar3 = param_1;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
  }
  else {
    local_2c[2] = param_2;
    local_2c[0] = param_4;
    local_2c[1] = param_3;
    local_2c[3] = 0;
    local_2c[4] = 0;
    piVar2 = local_2c;
    piVar3 = local_2c + 5;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    piVar2 = local_2c + 5;
    piVar3 = param_1;
    for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
  }
  return param_1;
}


