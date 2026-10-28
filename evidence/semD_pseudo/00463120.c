undefined4 __fastcall FUN_00463120(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (*(undefined4 **)(param_1 + 0x20) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x20))(1);
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  piVar2 = (int *)**(int **)(param_1 + 0x30);
  if (piVar2 != *(int **)(param_1 + 0x30)) {
    do {
      if ((undefined4 *)piVar2[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar2[2])(1);
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*(int *)(param_1 + 0x30));
  }
  piVar2 = (int *)**(int **)(param_1 + 0x30);
  if (piVar2 != *(int **)(param_1 + 0x30)) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_00402e90(piVar2,0xc);
      piVar2 = piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0x30));
  }
  *(undefined4 *)*(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(int *)(*(int *)(param_1 + 0x30) + 4) = *(int *)(param_1 + 0x30);
  return 1;
}


