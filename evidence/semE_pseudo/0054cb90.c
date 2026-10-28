void FUN_0054cb90(undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_005a4730;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    pvVar1 = _malloc(0x1f8);
    if (pvVar1 == (void *)0x0) {
      pvVar1 = (void *)FUN_00403440(0x1f8);
    }
    *param_1 = pvVar1;
  }
  ExceptionList = local_10;
  return;
}



void Catch_0054cbea(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(unaff_EBP + -0x14);
  for (puVar2 = *(undefined4 **)(unaff_EBP + 8); puVar2 < puVar1; puVar2 = puVar2 + 1) {
    FUN_005089fd(*puVar2);
  }
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(0,0);
}


