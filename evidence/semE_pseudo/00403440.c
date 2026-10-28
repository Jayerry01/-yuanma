void FUN_00403440(size_t param_1)

{
  void *pvVar1;
  undefined1 local_c [12];
  
  do {
    if (DAT_005d59fc == (code *)0x0) {
      FUN_004030d0(s_bad_allocation_005c42f4);
                    // WARNING: Subroutine does not return
      __CxxThrowException_8(local_c,&DAT_005b3d30);
    }
    (*DAT_005d59fc)();
    pvVar1 = _malloc(param_1);
  } while (pvVar1 == (void *)0x0);
  return;
}


