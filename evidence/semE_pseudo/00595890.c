undefined4 * FUN_00595890(void)

{
  undefined4 *puVar1;
  
  puVar1 = _malloc(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00596780(s_could_not_allocate_space_for_gsl_005d3b78,
                 s_E__ftp_gsl_1_0_interpolation_acc_005d3b50,0x21,8);
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[2] = 0;
    puVar1[1] = 0;
  }
  return puVar1;
}


