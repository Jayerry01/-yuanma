
undefined4 FUN_004f4d80(void)

{
  int *piVar1;
  int *unaff_retaddr;
  
  piVar1 = (int *)FUN_00487830();
  (**(code **)(*piVar1 + 0x1d8))(1);
  (**(code **)(*unaff_retaddr + 0xcc))(0);
  if (unaff_retaddr[0x69] != 0) {
    (**(code **)(*unaff_retaddr + 0x14))(unaff_retaddr[0x69]);
  }
  piVar1 = (int *)FUN_00487830();
  (**(code **)(*piVar1 + 0x304))(0);
  (**(code **)(*unaff_retaddr + 0x19c))(3);
  if (unaff_retaddr[0xfe] != 0) {
    *(undefined1 *)(unaff_retaddr[0xfe] + 0xd8) = 0;
  }
  if (unaff_retaddr[0xff] != 0) {
    *(undefined1 *)(unaff_retaddr[0xff] + 0xd8) = 0;
  }
  return 1;
}

