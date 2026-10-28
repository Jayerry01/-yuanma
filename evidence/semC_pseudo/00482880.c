FUN_00482880(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((*(uint *)(param_1 + 0x36e3c) < 0x11) && (*(int *)(param_1 + 0x36e40) == 0)) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x36c50) + 0x28))
                      (*(int **)(param_1 + 0x36c50),param_2,param_3,param_4,2,1,0x50);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x36c50) + 0x30))
                        (*(int **)(param_1 + 0x36c50),param_2,param_3,param_4,param_4,0x50);
      if (-1 < iVar1) {
        *param_5 = 0x50;
        return 1;
      }
    }
  }
  if ((*(uint *)(param_1 + 0x36e3c) < 0x10) && (*(uint *)(param_1 + 0x36e40) < 2)) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x36c50) + 0x28))
                      (*(int **)(param_1 + 0x36c50),param_2,param_3,param_4,2,1,0x49);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x36c50) + 0x30))
                        (*(int **)(param_1 + 0x36c50),param_2,param_3,param_4,param_4,0x49);
      if (-1 < iVar1) {
        *param_5 = 0x49;
        return 1;
      }
    }
  }
  if (*(uint *)(param_1 + 0x36e3c) < 0x19) {
    if (*(int *)(param_1 + 0x36e40) == 0) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x36c50) + 0x28))
                        (*(int **)(param_1 + 0x36c50),param_2,param_3,param_4,2,1,0x4d);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(**(int **)(param_1 + 0x36c50) + 0x30))
                          (*(int **)(param_1 + 0x36c50),param_2,param_3,param_4,param_4,0x4d);
        if (-1 < iVar1) {
          *param_5 = 0x4d;
          return 1;
        }
      }
    }
    if (*(uint *)(param_1 + 0x36e3c) < 0x19) {
      if (*(uint *)(param_1 + 0x36e40) < 9) {
        iVar1 = (**(code **)(**(int **)(param_1 + 0x36c50) + 0x28))
                          (*(int **)(param_1 + 0x36c50),param_2,param_3,param_4,2,1,0x4b);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(**(int **)(param_1 + 0x36c50) + 0x30))
                            (*(int **)(param_1 + 0x36c50),param_2,param_3,param_4,param_4,0x4b);
          if (-1 < iVar1) {
            *param_5 = 0x4b;
            return 1;
          }
        }
      }
      if ((*(uint *)(param_1 + 0x36e3c) < 0x19) && (*(uint *)(param_1 + 0x36e40) < 5)) {
        iVar1 = (**(code **)(**(int **)(param_1 + 0x36c50) + 0x28))
                          (*(int **)(param_1 + 0x36c50),param_2,param_3,param_4,2,1,0x4f);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(**(int **)(param_1 + 0x36c50) + 0x30))
                            (*(int **)(param_1 + 0x36c50),param_2,param_3,param_4,param_4,0x4f);
          if (-1 < iVar1) {
            *param_5 = 0x4f;
            return 1;
          }
        }
      }
    }
  }
  if ((*(uint *)(param_1 + 0x36e3c) < 0x21) && (*(int *)(param_1 + 0x36e40) == 0)) {
    puVar2 = param_3;
    iVar1 = (**(code **)(**(int **)(param_1 + 0x36c50) + 0x28))
                      (*(int **)(param_1 + 0x36c50),param_2,param_3,param_4,2,1,0x47);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x36c50) + 0x30))
                        (*(int **)(param_1 + 0x36c50),param_2,param_3,param_4,param_4,0x47);
      if (-1 < iVar1) {
        *puVar2 = 0x47;
        return 1;
      }
    }
  }
  return 0;
}


