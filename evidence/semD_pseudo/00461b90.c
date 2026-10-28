void __thiscall FUN_00461b90(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0xc);
  if (piVar2 != (int *)0x0) {
    if (piVar2[5] == 0) {
      iVar1 = FUN_004621a0();
      if (iVar1 == 0) {
        iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))(param_2,param_3);
        if (iVar1 != 0) {
          (**(code **)(**(int **)(param_1 + 0xc) + 0x40))(param_2,param_3);
          return;
        }
        piVar2 = (int *)**(int **)(param_1 + 0x14);
        if (piVar2 == *(int **)(param_1 + 0x14)) {
          return;
        }
        while (iVar1 = (**(code **)(*(int *)piVar2[2] + 0x14))(param_2,param_3), iVar1 == 0) {
          piVar2 = (int *)*piVar2;
          if (piVar2 == *(int **)(param_1 + 0x14)) {
            return;
          }
        }
      }
      else {
        piVar2 = (int *)**(int **)(param_1 + 0x14);
        if (piVar2 == *(int **)(param_1 + 0x14)) {
          return;
        }
        while ((iVar1 = FUN_004621a0(), iVar1 != 0 ||
               (iVar1 = (**(code **)(*(int *)piVar2[2] + 0x14))(param_2,param_3), iVar1 == 0))) {
          piVar2 = (int *)*piVar2;
          if (piVar2 == (int *)*(int *)(param_1 + 0x14)) {
            return;
          }
        }
      }
      (**(code **)(*(int *)piVar2[2] + 0x40))(param_2,param_3);
    }
    else {
      iVar1 = (**(code **)(*piVar2 + 0x14))(param_2,param_3);
      if (iVar1 != 0) {
        (**(code **)(**(int **)(param_1 + 0xc) + 0x40))(param_2,param_3);
        return;
      }
    }
  }
  return;
}


