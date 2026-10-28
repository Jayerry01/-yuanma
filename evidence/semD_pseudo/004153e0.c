void FUN_004153e0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6)

{
  int *piVar1;
  int iVar2;
  int local_2c [4];
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = local_2c;
  for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar1 = 0;
    piVar1 = piVar1 + 1;
  }
  local_2c[1] = param_2;
  local_2c[0] = 0x2c;
  local_1c = param_5;
  local_2c[2] = param_3;
  local_2c[3] = param_4;
  if (param_6 == 0) {
    local_18 = 0xbf800000;
    local_14 = 0x3f800000;
    local_10 = 2.0;
    local_c = 2.0;
  }
  else {
    local_10 = (float)param_4;
    local_18 = 0;
    local_14 = 0;
    local_c = (float)param_5;
  }
  local_8 = 0;
  local_4 = 0x3f800000;
  DAT_007e2768 = (**(code **)(**(int **)(param_1 + 0x30) + 0x44))
                           (*(int **)(param_1 + 0x30),local_2c);
  return;
}


