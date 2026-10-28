void __fastcall FUN_00461e10(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)**(int **)(param_1 + 0x14);
  if (piVar2 != *(int **)(param_1 + 0x14)) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_00402e90(piVar2,0xc);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0x14));
  }
  *(undefined4 *)*(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(int *)(*(int *)(param_1 + 0x14) + 4) = *(int *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


