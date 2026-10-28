void FUN_00433da0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_8;
  undefined4 local_4;
  
  if (((param_1 != 0) || (param_1 = DAT_005d9b74, DAT_005d9b74 != 0)) &&
     (*(int *)(param_1 + 0x34) != 0)) {
    local_8 = FUN_0041f6b0(param_2,param_3,param_4);
    *(undefined4 *)(param_1 + 4) = local_8;
    local_4 = local_8;
    (**(code **)(**(int **)(param_1 + 0x34) + 0x74))(*(int **)(param_1 + 0x34),8,&local_8);
  }
  return;
}


