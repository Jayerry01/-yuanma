void FUN_00429ee0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = (int *)FUN_0042a010(param_1);
  if ((((piVar2 != (int *)0x0) && (piVar2 = (int *)*piVar2, piVar2 != (int *)0x0)) && (-1 < param_2)
      ) && (param_2 < piVar2[9])) {
    uVar1 = *(undefined4 *)(*piVar2 + param_2 * 4);
    uVar3 = FUN_00434380(uVar1);
    FUN_00434440(uVar3,param_3,param_4,param_5,param_6,param_7,param_8);
    FUN_00434410(uVar1);
  }
  return;
}


