undefined4 * __thiscall FUN_005091cd(undefined4 *param_1,undefined4 *param_2)

{
  size_t sVar1;
  void *pvVar2;
  
  *param_1 = &PTR_FUN_005ac444;
  sVar1 = _strlen((char *)*param_2);
  pvVar2 = operator_new(sVar1 + 1);
  param_1[1] = pvVar2;
  if (pvVar2 != (void *)0x0) {
    FUN_0050f710(pvVar2,*param_2);
  }
  param_1[2] = 1;
  return param_1;
}



// Library Function - Single Match
//  public: virtual __thiscall exception::~exception(void)
// 
// Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release

void __thiscall exception::~exception(exception *this)

{
  *(undefined ***)this = &PTR_FUN_005ac444;
  if (*(int *)(this + 8) != 0) {
    FUN_00507850(*(undefined4 *)(this + 4));
  }
  return;
}


