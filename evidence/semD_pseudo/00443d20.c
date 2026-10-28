undefined4 __thiscall FUN_00443d20(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  if (*(code **)(param_1 + 0x38) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 0x38))(param_2,param_3);
    if (iVar1 != 0) {
      return 1;
    }
    if ((*(int *)(param_1 + 0x6c) == 1) &&
       (piVar2 = (int *)**(int **)(param_1 + 0x30), piVar2 != *(int **)(param_1 + 0x30))) {
      do {
        iVar1 = FUN_004621a0();
        if ((iVar1 == 0) &&
           (iVar1 = (**(code **)(*(int *)piVar2[2] + 0x10))(param_2,param_3), iVar1 != 0)) {
          return 1;
        }
        piVar2 = (int *)*piVar2;
      } while (piVar2 != (int *)*(int *)(param_1 + 0x30));
    }
  }
  return 0;
}


