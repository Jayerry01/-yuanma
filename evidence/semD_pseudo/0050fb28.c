void FUN_0050fb28(void)

{
  void *pvVar1;
  char *pcVar2;
  int local_c;
  int local_8;
  
  if (DAT_007f1d78 == 0) {
    FUN_00511234();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_0066771c,0x104);
  _DAT_00667694 = &DAT_0066771c;
  pcVar2 = &DAT_0066771c;
  if (*DAT_007f2ec4 != '\0') {
    pcVar2 = DAT_007f2ec4;
  }
  FUN_0050fbc1(pcVar2,0,0,&local_8,&local_c);
  pvVar1 = _malloc(local_c + local_8 * 4);
  if (pvVar1 == (void *)0x0) {
    __amsg_exit(8);
  }
  FUN_0050fbc1(pcVar2,pvVar1,(void *)((int)pvVar1 + local_8 * 4),&local_8,&local_c);
  _DAT_0066767c = pvVar1;
  _DAT_00667678 = local_8 + -1;
  return;
}


