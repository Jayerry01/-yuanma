void __thiscall FUN_005541f0(int param_1,short param_2)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  
  if ((*(int *)(param_1 + 0x3c) != *(int *)(param_1 + 0x2c)) &&
     (param_2 != *(short *)(param_1 + 0x10))) {
    *(short *)(param_1 + 0x10) = param_2;
    if (*(int *)(param_1 + 0x3c) != *(int *)(param_1 + 0x2c)) {
      do {
        sVar1 = **(short **)(param_1 + 0x2c);
        FUN_00554cb0();
        if (*(int *)(param_1 + 0x2c) == *(int *)(param_1 + 0x34) + -0x18) {
          FUN_004e8500();
          FUN_00402e90(*(undefined4 *)(param_1 + 0x30),0x1f8);
          piVar3 = (int *)(*(int *)(param_1 + 0x38) + 4);
          *(int **)(param_1 + 0x38) = piVar3;
          iVar2 = *piVar3;
          *(int *)(param_1 + 0x30) = iVar2;
          *(int *)(param_1 + 0x34) = iVar2 + 0x1f8;
          *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x30);
        }
        else {
          FUN_004e8500();
          *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 0x18;
        }
      } while ((sVar1 != param_2) && (*(int *)(param_1 + 0x3c) != *(int *)(param_1 + 0x2c)));
    }
    *(int *)(param_1 + 0x7c) =
         (*(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x2c)) / 0x18 +
         (*(int *)(param_1 + 0x3c) - *(int *)(param_1 + 0x40)) / 0x18 +
         (*(int *)(param_1 + 0x48) - *(int *)(param_1 + 0x38) >> 2) * 0x15 + -0x15;
  }
  return;
}


