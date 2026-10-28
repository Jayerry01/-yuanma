void FUN_0051c3fb(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  
  FastExitMediaState();
  uVar3 = PackedFloatingMUL(*param_2,*param_3);
  uVar5 = PackedFloatingMUL(param_2[1],param_3[1]);
  uVar5 = PackedFloatingADD(uVar3,uVar5);
  uVar3 = PackedFloatingSUB(0x3f800000,(ulonglong)param_4);
  uVar1 = (uint)uVar3;
  uVar4 = PackedFloatingAccumulate(uVar5,uVar5);
  uVar8 = PackedFloatingCompareGE(0,uVar4);
  uVar9 = uVar8 & 0x8000000080000000;
  uVar4 = uVar4 ^ uVar9;
  uVar5 = PackedFloatingCompareGE(0x3f7fff583f7fff58,uVar4);
  uVar3 = PackedFloatingMUL(uVar4,uVar4);
  uVar3 = PackedFloatingSUBR(uVar3,0x3f8000003f800000);
  if ((int)uVar5 != 0) {
    uVar6 = PackedFloatingReciprocalSQRAprox((ulonglong)param_4,uVar3);
    uVar5 = PackedFloatingMUL(uVar6,uVar6);
    uVar3 = PackedFloatingReciprocalSQRIter1(uVar3,uVar5);
    uVar6 = PackedFloatingReciprocalIter2(uVar3,uVar6);
    uVar3 = FloatingReciprocalAprox(uVar5,uVar6);
    uVar5 = PackedFloatingReciprocalIter1(uVar6,uVar3);
    PackedFloatingReciprocalIter2(uVar5,uVar3);
    uVar10 = (uint)uVar6;
    uVar3 = FUN_00522980();
    uVar11 = (uint)uVar3;
    PackedFloatingMUL(uVar3,(ulonglong)param_4);
    uVar2 = FUN_00523180(uVar1,uVar10,uVar11);
    PackedFloatingMUL((ulonglong)uVar11,(ulonglong)uVar1);
    uVar3 = FUN_00523180();
    uVar9 = uVar8 & 0x80000000;
    uVar3 = PackedFloatingMUL(uVar3,(ulonglong)uVar10);
    uVar1 = (uint)uVar3;
    uVar3 = PackedFloatingMUL((ulonglong)uVar2,(ulonglong)uVar10);
    param_4 = (uint)uVar3;
  }
  param_4 = param_4 ^ (uint)uVar9;
  uVar5 = CONCAT44(param_4,param_4);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),*param_2);
  uVar6 = PackedFloatingMUL(uVar5,*param_3);
  uVar7 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),param_2[1]);
  uVar5 = PackedFloatingMUL(uVar5,param_3[1]);
  uVar3 = PackedFloatingADD(uVar3,uVar6);
  uVar5 = PackedFloatingADD(uVar7,uVar5);
  *param_1 = uVar3;
  param_1[1] = uVar5;
  FastExitMediaState();
  return;
}



undefined4