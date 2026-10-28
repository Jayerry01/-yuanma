void __thiscall FUN_00477b30(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    uVar1 = param_1[8];
    uVar2 = param_1[4];
    *param_3 = *param_1;
    param_3[1] = uVar2;
    param_3[2] = uVar1;
  }
  else {
    if (param_2 == 1) {
      uVar1 = param_1[9];
      uVar2 = param_1[5];
      *param_3 = param_1[1];
      param_3[1] = uVar2;
      param_3[2] = uVar1;
      return;
    }
    if (param_2 == 2) {
      uVar1 = param_1[10];
      uVar2 = param_1[6];
      *param_3 = param_1[2];
      param_3[1] = uVar2;
      param_3[2] = uVar1;
      return;
    }
  }
  return;
}


