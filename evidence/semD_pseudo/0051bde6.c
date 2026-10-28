void FUN_0051bde6(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  uVar3 = *param_1;
  uVar1 = param_1[1];
  uVar4 = PackedFloatingMUL(uVar3,uVar3);
  uVar2 = PackedFloatingMUL(uVar1,uVar1);
  uVar4 = PackedFloatingADD(uVar4,uVar2);
  uVar4 = PackedFloatingAccumulate(uVar4,uVar4);
  uVar5 = PackedFloatingCompareGE(0x80000000800000,uVar4);
  uVar2 = PackedFloatingReciprocalSQRAprox(uVar2,uVar4);
  if ((int)uVar5 == 0) {
    uVar5 = PackedFloatingMUL(uVar2,uVar2);
    if (param_2 != (undefined8 *)0x0) {
      uVar4 = PackedFloatingReciprocalSQRIter1(uVar5,uVar4);
      uVar2 = PackedFloatingReciprocalIter2(uVar4,uVar2);
      uVar4 = PackedFloatingMUL(uVar3,uVar2);
      uVar3 = PackedFloatingMUL(uVar2,uVar1);
      *param_2 = uVar4;
      *(int *)(param_2 + 1) = (int)uVar3;
    }
    if (param_3 != (undefined4 *)0x0) {
      uVar3 = FUN_00522a80();
      uVar3 = PackedFloatingMUL(uVar3,0x4000000040000000);
      *param_3 = (int)uVar3;
    }
  }
  else {
    if (param_2 != (undefined8 *)0x0) {
      *(undefined8 *)((int)param_2 + 4) = 0;
      *(undefined4 *)param_2 = 0x3f800000;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0;
    }
  }
  FastExitMediaState();
  return;
}


