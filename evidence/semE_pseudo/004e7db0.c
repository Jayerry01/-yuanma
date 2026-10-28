undefined4 * __thiscall FUN_004e7db0(undefined4 *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_005ab064;
  if ((int *)param_1[0x14] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x14] + 8))(1);
  }
  if ((param_2 & 1) != 0) {
    FUN_00507850(param_1);
  }
  return param_1;
}


