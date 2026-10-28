undefined4 __fastcall FUN_004697b0(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)**(int **)(param_1 + 0x2c);
  if (piVar2 != *(int **)(param_1 + 0x2c)) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_00402e90(piVar2,0xc);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0x2c));
  }
  *(undefined4 *)*(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(int *)(*(int *)(param_1 + 0x2c) + 4) = *(int *)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return 1;
}


