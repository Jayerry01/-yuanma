void FUN_0053dca0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  param_1[1] = 0;
  if (param_2 != 0x3e) {
    *(undefined4 *)(*param_1 + 0x14) = 0xc;
    *(undefined4 *)(*param_1 + 0x18) = 0x3e;
    *(int *)(*param_1 + 0x1c) = param_2;
    (**(code **)*param_1)(param_1);
  }
  if (param_3 != 0x1b0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x15;
    *(undefined4 *)(*param_1 + 0x18) = 0x1b0;
    *(int *)(*param_1 + 0x1c) = param_3;
    (**(code **)*param_1)(param_1);
  }
  iVar4 = *param_1;
  iVar1 = param_1[3];
  piVar2 = param_1;
  for (iVar3 = 0x6c; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  *param_1 = iVar4;
  param_1[3] = iVar1;
  *(undefined1 *)(param_1 + 4) = 1;
  FUN_0053ec70(param_1);
  param_1[2] = 0;
  param_1[6] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  iVar4 = 4;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  piVar2 = param_1 + 0x2c;
  do {
    piVar2[-4] = 0;
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0x43] = 0;
  FUN_0053c480(param_1);
  FUN_0053e680(param_1);
  param_1[5] = 200;
  return;
}



void thunk_FUN_0053e300(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    (**(code **)(*(int *)(param_1 + 4) + 0x28))(param_1);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


