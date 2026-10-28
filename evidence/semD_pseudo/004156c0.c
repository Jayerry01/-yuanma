void FUN_004156c0(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar2 = param_1;
  if (param_1 != (int *)0x0) {
    if (DAT_005c4308 == 0) {
      if (param_1[0x15] != 0) {
        FUN_005089fd(param_1[0x15]);
        piVar2[0x15] = 0;
      }
      if (piVar2[0x16] != 0) {
        FUN_005089fd(piVar2[0x16]);
        piVar2[0x16] = 0;
      }
    }
    else {
      if (param_2 != 0) {
        if ((param_1[0x18] == 1) && (piVar1 = (int *)param_1[0x11], piVar1 != (int *)0x0)) {
          param_1 = (int *)0x0;
          local_10 = 0x20000;
          local_4 = 0;
          local_8 = 0;
          local_c = 0;
          (**(code **)(*piVar1 + 0x30))(piVar1,&local_10,&param_1);
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))(param_1);
          }
        }
        piVar1 = (int *)piVar2[0x10];
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          piVar2[0x10] = 0;
        }
        piVar1 = (int *)piVar2[0x11];
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          piVar2[0x11] = 0;
        }
      }
      if (param_3 != 0) {
        piVar1 = (int *)piVar2[0xe];
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          piVar2[0xe] = 0;
        }
        piVar1 = (int *)piVar2[0xf];
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
          piVar2[0xf] = 0;
          return;
        }
      }
    }
  }
  return;
}


