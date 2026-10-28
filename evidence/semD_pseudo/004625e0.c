undefined4 __thiscall FUN_004625e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *piVar2;
  
  if (*(code **)(param_1 + 0x54) != (code *)0x0) {
    (**(code **)(param_1 + 0x54))(param_2,param_3);
  }
  if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x14))(param_2,param_3);
    if (iVar1 == 0) {
      piVar2 = (int *)**(int **)(param_1 + 0x30);
      if (piVar2 != *(int **)(param_1 + 0x30)) {
        do {
          if (((piVar2[2] != *(int *)(param_1 + 0x1c)) && (iVar1 = FUN_004621a0(), iVar1 == 0)) &&
             (iVar1 = (**(code **)(*extraout_ECX_00 + 0x14))(param_2,param_3), iVar1 != 0)) {
            (**(code **)(*(int *)piVar2[2] + 0x40))(param_2,param_3);
            iVar1 = FUN_00462190();
            if (iVar1 != 0) {
              return 1;
            }
          }
          piVar2 = (int *)*piVar2;
        } while (piVar2 != (int *)*(int *)(param_1 + 0x30));
      }
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x40))(param_2,param_3);
      iVar1 = FUN_00462190();
      if ((iVar1 == 0) &&
         (piVar2 = (int *)**(int **)(param_1 + 0x30), piVar2 != *(int **)(param_1 + 0x30))) {
        do {
          if ((piVar2[2] != *(int *)(param_1 + 0x1c)) &&
             ((iVar1 = FUN_004621a0(), iVar1 == 0 &&
              (iVar1 = (**(code **)(*extraout_ECX + 0x14))(param_2,param_3), iVar1 != 0)))) {
            (**(code **)(*(int *)piVar2[2] + 0x40))(param_2,param_3);
            iVar1 = FUN_00462190();
            if (iVar1 != 0) {
              return 1;
            }
          }
          piVar2 = (int *)*piVar2;
        } while (piVar2 != (int *)*(int *)(param_1 + 0x30));
        return 1;
      }
    }
  }
  return 1;
}


