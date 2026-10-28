
undefined4 FUN_004f4d50(void)

{
  int *piVar1;
  int *unaff_retaddr;
  
  piVar1 = (int *)FUN_00487830();
  (**(code **)(*piVar1 + 0x1d8))(0);
  if (unaff_retaddr[0x69] != 0) {
    (**(code **)(*unaff_retaddr + 0x10))(unaff_retaddr[0x69]);
  }
  return 1;
}

