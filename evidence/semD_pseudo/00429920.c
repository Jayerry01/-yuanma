void FUN_00429920(void)

{
  int *piVar1;
  
  piVar1 = &DAT_007ddf40;
  do {
    if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
      FUN_00434ac0(*(undefined4 *)*piVar1);
      if (*(int *)(*piVar1 + 4) != 0) {
        FUN_005089fd(*(int *)(*piVar1 + 4));
      }
      FUN_005089fd(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x7dff40);
  *(undefined4 *)(DAT_005d5a0c + 0x6cc) = 0;
  *(undefined4 *)(DAT_005d5a0c + 0x6d0) = 0;
  DAT_005d5b00 = 0;
  return;
}


