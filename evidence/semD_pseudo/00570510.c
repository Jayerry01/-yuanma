uint FUN_00570510(float *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  undefined1 local_58 [12];
  undefined1 local_4c [12];
  undefined1 local_40 [64];
  
  local_70 = -*param_1;
  local_64 = *param_1;
  local_60 = param_1[1];
  local_5c = param_1[2];
  local_6c = -param_1[1];
  local_68 = -param_1[2];
  FUN_00477ad0(local_40);
  FUN_00476e80(local_4c,param_3,local_40);
  FUN_00476e80(local_58,param_4,local_40);
  uVar2 = FUN_005702d0(&local_70,&local_64,local_4c,local_58,param_5,0);
  if ((char)uVar2 != '\0') {
    puVar3 = (undefined4 *)FUN_00476e80(&local_64,param_5,param_2);
    *param_5 = *puVar3;
    param_5[1] = puVar3[1];
    uVar1 = puVar3[2];
    param_5[2] = uVar1;
    return CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  return uVar2 & 0xffffff00;
}


