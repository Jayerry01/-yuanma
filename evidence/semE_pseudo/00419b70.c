void FUN_00419b70(int *param_1,int param_2,undefined4 param_3)

{
  if ((param_2 != 0) && (0 < *(int *)(param_2 + 0x18))) {
    DAT_005c4618 = 0xfffffffe;
    FUN_0041a490(param_1,1);
    (**(code **)(*param_1 + 0x70))
              (param_1,1,0x112,*(undefined4 *)(param_2 + 0x1c),*(undefined4 *)(param_2 + 0x18),
               param_3);
    DAT_005c4618 = 0xffffffff;
    FUN_0041a490(param_1,1);
  }
  return;
}


