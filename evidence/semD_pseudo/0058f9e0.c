void __thiscall FUN_0058f9e0(int param_1,float param_2,int param_3)

{
  double dVar1;
  double local_10;
  
  if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x1ec) + 0xe4) < 3) {
    FUN_0058ef40(param_2,param_3);
    return;
  }
  dVar1 = (double)(param_2 * *(float *)(param_3 + 0x20) + *(float *)(param_3 + 0x18));
  local_10 = dVar1;
  FUN_00595374(*(undefined4 *)(param_1 + 0x8c),*(undefined4 *)(param_1 + 0xa4),
               *(undefined4 *)(param_1 + 0xa8),dVar1,*(undefined4 *)(param_1 + 0x98),&local_10);
  *(float *)(param_1 + 0x18) = (float)local_10;
  FUN_00595374(*(undefined4 *)(param_1 + 0x90),*(undefined4 *)(param_1 + 0xa4),
               *(undefined4 *)(param_1 + 0xac),dVar1,*(undefined4 *)(param_1 + 0x9c),&local_10);
  *(float *)(param_1 + 0x1c) = (float)local_10;
  FUN_00595374(*(undefined4 *)(param_1 + 0x94),*(undefined4 *)(param_1 + 0xa4),
               *(undefined4 *)(param_1 + 0xb0),dVar1,*(undefined4 *)(param_1 + 0xa0),&local_10);
  *(float *)(param_1 + 0x20) = (float)local_10;
  return;
}


