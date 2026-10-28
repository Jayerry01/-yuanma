void FUN_00475090(undefined4 *param_1,undefined4 *param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_30 [4];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18 [6];
  
  local_30[0] = *param_1;
  local_30[1] = param_1[1];
  local_30[2] = param_1[2];
  local_30[3] = DAT_005e07d0;
  if (param_3 != (undefined1 *)0x0) {
    local_30[3] = FUN_00475c50(*param_3,param_3[1],param_3[2],param_3[3]);
  }
  uVar1 = DAT_005e04e0;
  local_20 = 0;
  local_1c = 0;
  puVar3 = local_30;
  puVar4 = local_18;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  local_18[0] = *param_2;
  local_18[1] = param_2[1];
  local_18[2] = param_2[2];
  FUN_00474e90(4);
  FUN_004754f0(3,local_30,2,1);
  FUN_00474e90(uVar1);
  return;
}


