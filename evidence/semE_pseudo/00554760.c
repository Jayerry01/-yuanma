void FUN_00554760(u_long *param_1,undefined4 *param_2)

{
  u_short uVar1;
  u_long uVar2;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  *(undefined2 *)param_2 = 2;
  uVar2 = htonl(*param_1);
  param_2[1] = uVar2;
  uVar1 = htons((u_short)param_1[1]);
  *(u_short *)((int)param_2 + 2) = uVar1;
  return;
}


