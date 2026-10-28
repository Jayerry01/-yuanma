FUN_004784e0(undefined4 *param_1,float param_2,float param_3,float param_4,float param_5,
            float param_6,float param_7,char param_8)

{
  undefined4 *puVar1;
  int iVar2;
  float local_80 [5];
  float local_6c;
  float local_58;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  undefined1 local_40 [64];
  
  FUN_00477200();
  if (param_8 == '\0') {
    local_58 = 1.0 / (param_6 - param_7);
    local_50 = (param_2 + param_3) / (param_3 - param_2);
    local_4c = (param_4 + param_5) / (param_5 - param_4);
    local_48 = local_58 * param_6;
  }
  else {
    local_58 = -2.0 / (param_7 - param_6);
    local_50 = (param_2 + param_3) / (param_3 - param_2);
    local_4c = (param_4 + param_5) / (param_5 - param_4);
    local_48 = -((param_6 + param_7) / (param_7 - param_6));
  }
  local_4c = -local_4c;
  local_50 = -local_50;
  local_6c = 2.0 / (param_5 - param_4);
  local_80[0] = 2.0 / (param_3 - param_2);
  local_44 = 0x3f800000;
  puVar1 = (undefined4 *)FUN_00476f00(local_40,local_80,param_1);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *puVar1;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  }
  return;
}



void __thiscall