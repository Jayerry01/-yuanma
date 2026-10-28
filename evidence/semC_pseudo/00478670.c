FUN_00478670(undefined4 *param_1,float param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  int iVar5;
  float local_80;
  float local_7c;
  float local_78;
  undefined4 local_74;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [64];
  
  fVar2 = param_3 + param_3;
  fVar3 = param_4 + param_4;
  local_50 = 0;
  fVar1 = param_2 * (param_2 + param_2);
  local_4c = 0;
  local_48 = 0;
  local_74 = 0;
  local_64 = 0;
  local_54 = 0;
  local_44 = 0x3f800000;
  local_68 = param_5 * (param_2 + param_2);
  local_80 = 1.0 - (param_4 * fVar3 + param_3 * fVar2);
  local_70 = param_2 * fVar2 - param_5 * fVar3;
  local_60 = param_5 * fVar2 + fVar3 * param_2;
  local_7c = param_5 * fVar3 + param_2 * fVar2;
  local_6c = 1.0 - (param_4 * fVar3 + fVar1);
  local_5c = fVar3 * param_3 - local_68;
  local_78 = fVar3 * param_2 - param_5 * fVar2;
  local_68 = local_68 + fVar3 * param_3;
  local_58 = 1.0 - (param_3 * fVar2 + fVar1);
  puVar4 = (undefined4 *)FUN_00476f00(local_40,&local_80,param_1);
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *param_1 = *puVar4;
    puVar4 = puVar4 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


