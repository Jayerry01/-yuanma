void __fastcall FUN_0055b260(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  float10 fVar4;
  
  piVar2 = (int *)**(int **)(param_1 + 0x167c);
  if (piVar2 != *(int **)(param_1 + 0x167c)) {
    do {
      fVar4 = (float10)FUN_004748b0();
      piVar2[4] = (int)(float)(fVar4 + (float10)(float)piVar2[4]);
      if ((float)piVar2[4] <= 3.0) {
        piVar3 = (int *)*piVar2;
      }
      else {
        piVar1 = (int *)piVar2[1];
        piVar3 = (int *)*piVar2;
        *piVar1 = (int)piVar3;
        piVar3[1] = (int)piVar1;
        FUN_00402e90(piVar2,0x14);
      }
      piVar2 = piVar3;
    } while (piVar3 != *(int **)(param_1 + 0x167c));
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
