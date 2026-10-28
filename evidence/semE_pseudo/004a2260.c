int __thiscall FUN_004a2260(int *param_1,int *param_2)

{
  return (param_1[3] - param_2[3] >> 2) * 0x20 + (*param_1 - param_1[1] >> 4) + -0x20 +
         (param_2[2] - *param_2 >> 4);
}



void __thiscall