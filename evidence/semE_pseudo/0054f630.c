undefined4 __thiscall FUN_0054f630(int param_1,int *param_2,int *param_3)

{
  return *(undefined4 *)
          (param_1 + 0x2c +
          ((*param_3 * 3 + ((uint)*(ushort *)(param_2 + 1) + (uint)*(ushort *)(param_3 + 1) * 2) * 2
           + *param_2) % 0x32) * 4);
}


