void __fastcall FUN_00488230(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)**(int **)(param_1 + 0x2960);
  if (piVar2 != *(int **)(param_1 + 0x2960)) {
    do {
      if ((undefined4 *)piVar2[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar2[2])(1);
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*(int *)(param_1 + 0x2960));
  }
  piVar2 = (int *)**(int **)(param_1 + 0x2960);
  if (piVar2 != *(int **)(param_1 + 0x2960)) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_00402e90(piVar2,0xc);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0x2960));
  }
  *(undefined4 *)*(undefined4 *)(param_1 + 0x2960) = *(undefined4 *)(param_1 + 0x2960);
  *(int *)(*(int *)(param_1 + 0x2960) + 4) = *(int *)(param_1 + 0x2960);
  return;
}


