void FUN_00429fd0(undefined4 param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_0042a010(param_1);
  if ((((piVar1 != (int *)0x0) && (piVar1 = (int *)*piVar1, piVar1 != (int *)0x0)) && (-1 < param_2)
      ) && (param_2 < piVar1[9])) {
    FUN_00434410(*(undefined4 *)(*piVar1 + param_2 * 4));
  }
  return;
}


