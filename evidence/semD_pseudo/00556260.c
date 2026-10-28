void FUN_00556260(void)

{
  int in_stack_00000014;
  int in_stack_00000018;
  int in_stack_0000001c;
  int *in_stack_00000020;
  int local_10;
  
  FUN_004e6050(&stack0x00000014);
  FUN_004e6050(&stack0x00000004);
  while (in_stack_00000014 != local_10) {
    FUN_004e8500();
    in_stack_00000014 = in_stack_00000014 + 0x18;
    if (in_stack_00000014 == in_stack_0000001c) {
      in_stack_00000020 = in_stack_00000020 + 1;
      in_stack_00000014 = *in_stack_00000020;
      in_stack_0000001c = in_stack_00000014 + 0x1f8;
      in_stack_00000018 = in_stack_00000014;
    }
  }
  return;
}


