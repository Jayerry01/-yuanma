void __thiscall FUN_004b40a0(float *param_1,undefined4 param_2)

{
  float fVar1;
  float10 fVar2;
  float local_24 [6];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a0748;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00549d20(0,0);
  local_4 = 0;
  FUN_00549da0(param_2,0xc);
  thunk_FUN_00549ee0(local_24,7);
  fVar1 = ((float)(int)local_24[0] - 64.0) * 0.5 + param_1[9];
  param_1[9] = fVar1;
  *param_1 = fVar1;
  thunk_FUN_00549ee0(local_24,7);
  fVar1 = ((float)(int)local_24[0] - 64.0) * 0.5 + param_1[10];
  param_1[10] = fVar1;
  param_1[1] = fVar1;
  thunk_FUN_00549ee0(local_24,7);
  fVar1 = ((float)(int)local_24[0] - 64.0) * 0.5 + param_1[0xb];
  param_1[0xb] = fVar1;
  param_1[2] = fVar1;
  thunk_FUN_00549ee0(local_24,7);
  param_1[5] = 0.0;
  fVar2 = (float10)fcos((float10)(int)local_24[0] * (float10)0.05);
  param_1[3] = (float)fVar2;
  fVar2 = (float10)fsin((float10)(int)local_24[0] * (float10)0.05);
  param_1[4] = (float)fVar2;
  thunk_FUN_00549ee0(local_24,0xc);
  param_1[0xc] = ((float)(int)local_24[0] - 2048.0) * 0.25;
  thunk_FUN_00549ee0(local_24,0xc);
  param_1[0xd] = ((float)(int)local_24[0] - 2048.0) * 0.25;
  thunk_FUN_00549ee0(local_24,0xc);
  param_1[0xe] = ((float)(int)local_24[0] - 2048.0) * 0.25;
  thunk_FUN_00549ee0(local_24,0x10);
  param_1[0xf] = local_24[0];
  thunk_FUN_00549ee0(local_24,0x10);
  param_1[0x10] = local_24[0];
  local_4 = 0xffffffff;
  FUN_00549d80();
  ExceptionList = local_c;
  return;
}


