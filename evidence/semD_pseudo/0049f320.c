void FUN_0049f320(int param_1)

{
  int in_stack_00000014;
  undefined4 in_stack_00000018;
  int in_stack_0000001c;
  int *in_stack_00000020;
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  FUN_004e6050(&stack0x00000014);
  FUN_004e6050(&param_1);
  FUN_004e6050(local_20);
  FUN_004e6050(local_10);
  while (in_stack_00000014 != param_1) {
    in_stack_00000014 = in_stack_00000014 + 0xc;
    if (in_stack_00000014 == in_stack_0000001c) {
      in_stack_00000020 = in_stack_00000020 + 1;
      in_stack_00000014 = *in_stack_00000020;
      in_stack_0000001c = in_stack_00000014 + 0x1f8;
    }
  }
  return;
}


