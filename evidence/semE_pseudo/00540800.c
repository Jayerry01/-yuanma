void FUN_00540800(int param_1)

{
  int iVar1;
  char cVar2;
  
  iVar1 = *(int *)(param_1 + 0x188);
  if (*(int *)(iVar1 + 0x10) != 0) {
    if (*(char *)(param_1 + 0x49) != '\0') {
      cVar2 = FUN_00540e50(param_1);
      if (cVar2 != '\0') {
        *(undefined1 **)(iVar1 + 0xc) = &LAB_00540f70;
        *(undefined4 *)(param_1 + 0x88) = 0;
        return;
      }
    }
    *(undefined1 **)(iVar1 + 0xc) = &LAB_00540c90;
  }
  *(undefined4 *)(param_1 + 0x88) = 0;
  return;
}


