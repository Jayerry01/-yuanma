void FUN_0054c870(int param_1)

{
  int in_stack_00000014;
  int in_stack_00000018;
  int in_stack_0000001c;
  int *in_stack_00000020;
  int local_30;
  int local_2c;
  int local_28;
  int *local_24;
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  local_2c = in_stack_00000018;
  local_30 = in_stack_00000014;
  local_28 = in_stack_0000001c;
  local_24 = in_stack_00000020;
  FUN_004e6050(&param_1);
  FUN_004e6050(&local_30);
  FUN_004e6050(local_20);
  FUN_004e6050(local_10);
  FUN_004e6050(&local_30);
  if (in_stack_00000014 != param_1) {
    do {
      FUN_004e8500();
      in_stack_00000014 = in_stack_00000014 + 0x18;
      if (in_stack_00000014 == in_stack_0000001c) {
        in_stack_00000020 = in_stack_00000020 + 1;
        in_stack_00000014 = *in_stack_00000020;
        in_stack_0000001c = in_stack_00000014 + 0x1f8;
        in_stack_00000018 = in_stack_00000014;
      }
    } while (in_stack_00000014 != param_1);
  }
  return;
}


