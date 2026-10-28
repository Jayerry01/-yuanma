void __thiscall FUN_004781d0(float *param_1,float param_2,float param_3,float param_4,char param_5)

{
  int iVar1;
  float *pfVar2;
  undefined1 local_80 [48];
  float local_50;
  float local_4c;
  float local_48;
  float local_40 [16];
  
  if (param_5 != '\0') {
    FUN_00477200();
    local_50 = param_2;
    local_4c = param_3;
    local_48 = param_4;
    FUN_00476f00(local_40,param_1,local_80);
    pfVar2 = local_40;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *pfVar2;
      pfVar2 = pfVar2 + 1;
      param_1 = param_1 + 1;
    }
    return;
  }
  param_1[0xc] = param_2 * *param_1 + param_4 * param_1[8] + param_3 * param_1[4] + param_1[0xc];
  param_1[0xd] = param_4 * param_1[9] + param_3 * param_1[5] + param_2 * param_1[1] + param_1[0xd];
  param_1[0xe] = param_4 * param_1[10] + param_3 * param_1[6] + param_2 * param_1[2] + param_1[0xe];
  param_1[0xf] = param_4 * param_1[0xb] + param_3 * param_1[7] + param_2 * param_1[3] + param_1[0xf]
  ;
  return;
}



undefined4 __thiscall