void __fastcall FUN_0055e050(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = FUN_00567220();
  if (iVar2 != 0) {
    FUN_00566750(param_1);
  }
  piVar3 = (int *)**(int **)(param_1 + 0x658);
  if (piVar3 != *(int **)(param_1 + 0x658)) {
    do {
      piVar1 = (int *)*piVar3;
      FUN_00402e90(piVar3,0xc);
      piVar3 = piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0x658));
  }
  *(undefined4 *)*(undefined4 *)(param_1 + 0x658) = *(undefined4 *)(param_1 + 0x658);
  *(int *)(*(int *)(param_1 + 0x658) + 4) = *(int *)(param_1 + 0x658);
  return;
}


