undefined4 __fastcall FUN_00469a00(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  
  uVar2 = 0;
  for (puVar1 = (undefined4 *)**(undefined4 **)(param_1 + 0x2c);
      puVar1 != *(undefined4 **)(param_1 + 0x2c); puVar1 = (undefined4 *)*puVar1) {
    uVar2 = uVar2 + 1;
  }
  if (uVar2 <= (uint)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0xc))) {
    return 0;
  }
  piVar3 = (int *)**(int **)(param_1 + 0x2c);
  if (piVar3 != *(int **)(param_1 + 0x2c)) {
    do {
      FUN_00466300();
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)*(int *)(param_1 + 0x2c));
  }
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  return 1;
}


