void FUN_00408ad0(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float10 fVar1;
  undefined1 local_3c [12];
  undefined1 local_30 [48];
  
  fVar1 = (float10)FUN_00529c80(param_3,param_4);
  fVar1 = fVar1 - (float10)1.0;
  if (fVar1 <= (float10)0.0) {
    fVar1 = -fVar1;
  }
  if ((float10)1e-06 < fVar1) {
    FUN_00430e80(local_3c,param_3,param_4);
    fVar1 = (float10)FUN_00509d10();
    FUN_00431a80(local_30,param_2,local_3c,(float)(fVar1 * (float10)57.295826));
    thunk_FUN_0040c620(*param_1 | 0x2000000,local_30,2);
  }
  return;
}



undefined4