void FUN_00433e00(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 *puStack_6c;
  undefined4 local_64 [20];
  undefined4 local_14;
  
  if (((param_1 != (int *)0x0) || (param_1 = DAT_005d9b74, DAT_005d9b74 != (int *)0x0)) &&
     (param_1[0xd] != 0)) {
    puStack_6c = (undefined4 *)param_4;
    uStack_70 = param_3;
    uStack_74 = param_2;
    local_64[0] = 100;
    uStack_78 = 0x433e39;
    local_14 = FUN_0041f6b0();
    puStack_6c = local_64;
    uStack_70 = 0x400;
    uStack_74 = 0;
    uStack_78 = 0;
    uStack_7c = 0;
    (**(code **)(*(int *)param_1[0xd] + 0x14))((int *)param_1[0xd]);
    if ((-1 < *param_1) && (piVar1 = (int *)(&DAT_005d7b70)[*param_1], piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0x14))(piVar1,0,0,0,0x400,&uStack_7c);
    }
  }
  return;
}


