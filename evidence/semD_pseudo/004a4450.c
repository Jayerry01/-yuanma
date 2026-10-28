int * __fastcall FUN_004a4450(int *param_1)

{
  void *pvVar1;
  int *piVar2;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059fb6b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x484);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_004a2e10();
  }
  local_4 = 0xffffffff;
  (**(code **)(*param_1 + 100))(piVar2);
  if (param_1[1] != 0) {
    (**(code **)(*piVar2 + 0x10))(param_1[1]);
  }
  (**(code **)(*piVar2 + 4))(0);
  ExceptionList = unaff_ESI;
  return piVar2;
}


