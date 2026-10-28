void * FUN_0049f5d0(undefined4 *param_1)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0059f561;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = _malloc(0x2b8);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)FUN_00403440(0x2b8);
  }
  local_8 = 2;
  if ((undefined4 *)((int)pvVar1 + 0x10) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 0x10) = *param_1;
    FUN_0049a750(param_1 + 2);
  }
  ExceptionList = local_10;
  return pvVar1;
}



void Catch_0049f659(void)

{
  int unaff_EBP;
  
  FUN_005089fd(*(undefined4 *)(unaff_EBP + -0x14));
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(0,0);
}


