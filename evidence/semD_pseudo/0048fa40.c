void __fastcall FUN_0048fa40(int *param_1)

{
  (**(code **)(*param_1 + 0x1bc))();
  if ((undefined4 *)param_1[0x84b] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x84b])(1);
    param_1[0x84b] = 0;
  }
  (**(code **)(*param_1 + 0x130))();
  if ((undefined4 *)param_1[0x860] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x860])(1);
  }
  param_1[0x860] = 0;
  if (param_1[0x902] != 0) {
    FUN_00507850(param_1[0x902]);
  }
  param_1[0x902] = 0;
  if ((undefined4 *)param_1[0x8ed] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x8ed])(1);
    param_1[0x8ed] = 0;
  }
  return;
}


