int __thiscall FUN_00561c60(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  iVar1 = *(int *)(param_1 + 0x4a0);
  if (iVar1 <= param_2) {
    param_2 = iVar1 + -1;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (*(int *)(param_1 + 0x4a4) <= param_3) {
    param_3 = *(int *)(param_1 + 0x4a4) + -1;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  if (*(int *)(param_1 + 0x4a8) <= param_4) {
    param_4 = *(int *)(param_1 + 0x4a8) + -1;
  }
  return *(int *)(param_1 + 0x2ec) +
         (iVar1 * param_3 + param_2 + *(int *)(param_1 + 0x4ac) * param_4) * 0x58;
}


