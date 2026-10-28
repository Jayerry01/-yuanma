void FUN_004e7cf0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,
                 int param_5,undefined4 *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *in_stack_00000028;
  undefined4 *in_stack_0000002c;
  undefined4 *in_stack_00000030;
  int in_stack_00000034;
  
  puVar2 = in_stack_00000030;
  iVar1 = param_5;
  while (param_2 != param_6) {
    if (in_stack_00000028 != (undefined4 *)0x0) {
      *in_stack_00000028 = *param_2;
      in_stack_00000028[1] = param_2[1];
      in_stack_00000028[2] = param_2[2];
      iVar1 = param_5;
      puVar2 = in_stack_00000030;
    }
    param_2 = param_2 + 3;
    if (param_2 == param_4) {
      param_2 = *(undefined4 **)(iVar1 + 4);
      iVar1 = iVar1 + 4;
      param_4 = param_2 + 0x7e;
      param_5 = iVar1;
    }
    in_stack_00000028 = in_stack_00000028 + 3;
    if (in_stack_00000028 == puVar2) {
      in_stack_00000028 = *(undefined4 **)(in_stack_00000034 + 4);
      in_stack_00000034 = in_stack_00000034 + 4;
      in_stack_00000030 = in_stack_00000028 + 0x7e;
      in_stack_0000002c = in_stack_00000028;
      puVar2 = in_stack_00000030;
    }
  }
  param_1[2] = puVar2;
  param_1[1] = in_stack_0000002c;
  *param_1 = in_stack_00000028;
  param_1[3] = in_stack_00000034;
  return;
}


