void FUN_005548a0(u_long *param_1,int param_2)

{
  u_short uVar1;
  u_long uVar2;
  
  uVar2 = ntohl(*(u_long *)(param_2 + 4));
  *param_1 = uVar2;
  uVar1 = ntohs(*(u_short *)(param_2 + 2));
  *(u_short *)(param_1 + 1) = uVar1;
  return;
}


