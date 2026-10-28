void FUN_005260b0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  char cVar2;
  
  FUN_00525610(param_1);
  if ((*(int *)(*(int *)(param_1 + 0x60) + 0x124) != 0) &&
     (*(int *)(*(int *)(param_1 + 0x60) + 0x130) != 0)) {
    if (param_2 == 1) {
      cVar2 = FUN_00528e40(param_3);
      if ((cVar2 != '\0') && (*(int *)(param_3 + 0xe30) != 0)) {
        FUN_00526310(param_1,param_3);
        if ((*(char *)(param_3 + 0xe02) != '\0') &&
           (piVar1 = *(int **)(param_3 + 0xe34), piVar1 != (int *)0x0)) {
          (**(code **)(*piVar1 + 0x30))(piVar1,0,0,1);
          *(undefined1 *)(param_3 + 0xe02) = 0;
          FUN_00525620(param_1);
          return;
        }
      }
    }
    else if ((param_2 == 2) && (*(int *)(param_1 + 0x34) != 0)) {
      FUN_005271a0(param_1);
    }
  }
  FUN_00525620(param_1);
  return;
}


