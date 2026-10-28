void __fastcall FUN_00492ee0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  (**(code **)(*(int *)(param_1 + 0x2488) + 0x10c))();
  iVar4 = *(int *)(*(int *)(param_1 + 0x2188) + 8);
  if (iVar4 != *(int *)(param_1 + 0x2188)) {
    do {
      if (*(int *)(iVar4 + 0x14) == 0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = (int *)(*(int *)(iVar4 + 0x14) + -0x65c);
      }
      (**(code **)(*piVar3 + 0x40))();
      iVar2 = *(int *)(iVar4 + 0xc);
      if (iVar2 == 0) {
        iVar2 = *(int *)(iVar4 + 4);
        if (iVar4 == *(int *)(iVar2 + 0xc)) {
          do {
            iVar4 = iVar2;
            iVar2 = *(int *)(iVar4 + 4);
          } while (iVar4 == *(int *)(iVar2 + 0xc));
        }
        if (*(int *)(iVar4 + 0xc) != iVar2) {
          iVar4 = iVar2;
        }
      }
      else {
        for (iVar1 = *(int *)(iVar2 + 8); iVar4 = iVar2, iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
          iVar2 = iVar1;
        }
      }
    } while (iVar4 != *(int *)(param_1 + 0x2188));
  }
  return;
}


