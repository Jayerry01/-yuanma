void FUN_00473de0(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = &DAT_007f0680;
  do {
    if (*piVar2 != 0) {
      piVar1 = *(int **)(*piVar2 + 0x40);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *(undefined4 *)(*piVar2 + 0x40) = 0;
      }
      piVar1 = *(int **)(*piVar2 + 0x44);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *(undefined4 *)(*piVar2 + 0x44) = 0;
      }
    }
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0x7f1680);
  return;
}


