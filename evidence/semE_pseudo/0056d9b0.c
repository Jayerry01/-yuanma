void __thiscall FUN_0056d9b0(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)**(int **)(param_1 + 0x24c);
  if (piVar1 != *(int **)(param_1 + 0x24c)) {
    do {
      if (param_2 == 0) {
        if (*(int *)(piVar1[2] + 0x68) == 0) {
LAB_0056d9ec:
          FUN_005592c0(1);
        }
      }
      else if (param_2 == 1) {
        if (*(int *)(piVar1[2] + 0x68) != 0) goto LAB_0056d9ec;
      }
      else if (param_2 == 2) {
        FUN_00559290();
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0x24c));
  }
  return;
}


