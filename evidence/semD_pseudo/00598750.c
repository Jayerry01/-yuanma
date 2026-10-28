int * FUN_00598750(int *param_1,undefined4 param_2,int param_3)

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
  if (param_3 == 0) {
    FUN_00596780(s_vector_length_n_must_be_positive_005d4904,
                 s_E__ftp_gsl_1_0_vector_view_sourc_005d48e0,0x1c,4);
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
    local_2c[0] = param_3;
    local_2c[1] = 1;
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


