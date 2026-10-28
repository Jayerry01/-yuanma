void FUN_00596135(int param_1,double param_2,double param_3,int param_4,double *param_5,
                 undefined4 *param_6,double *param_7)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = *(undefined4 *)(param_1 + param_4 * 8);
  uVar2 = *(undefined4 *)(param_1 + 4 + param_4 * 8);
  uVar3 = *(undefined4 *)(param_1 + 8 + param_4 * 8);
  uVar4 = *(undefined4 *)(param_1 + 0xc + param_4 * 8);
  *param_5 = param_2 / param_3 -
             (((double)CONCAT44(uVar2,uVar1) * 2.0 + (double)CONCAT44(uVar4,uVar3)) * param_3) / 3.0
  ;
  *param_6 = uVar1;
  param_6[1] = uVar2;
  *param_7 = ((double)CONCAT44(uVar4,uVar3) - (double)CONCAT44(uVar2,uVar1)) / (param_3 * 3.0);
  return;
}



undefined4