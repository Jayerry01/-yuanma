int * __fastcall FUN_00476220(int *param_1)

{
  void *pvVar1;
  undefined1 local_c [12];
  
  pvVar1 = _malloc(0xa8);
  while( true ) {
    if (pvVar1 != (void *)0x0) {
      *param_1 = (int)pvVar1;
      *(void **)pvVar1 = pvVar1;
      *(int *)(*param_1 + 4) = *param_1;
      return param_1;
    }
    if (DAT_005d59fc == (code *)0x0) break;
    (*DAT_005d59fc)();
    pvVar1 = _malloc(0xa8);
  }
  FUN_004030d0(s_bad_allocation_005c42f4);
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(local_c,&DAT_005b3d30);
}


