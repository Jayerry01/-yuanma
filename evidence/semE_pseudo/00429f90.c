undefined4 FUN_00429f90(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)FUN_0042a010(param_1);
  if ((((piVar1 != (int *)0x0) && (piVar1 = (int *)*piVar1, piVar1 != (int *)0x0)) && (-1 < param_2)
      ) && (param_2 < piVar1[9])) {
    uVar2 = FUN_00434380(*(undefined4 *)(*piVar1 + param_2 * 4));
    return uVar2;
  }
  return 0;
}


