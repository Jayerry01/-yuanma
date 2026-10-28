void __fastcall FUN_005629d0(int param_1)

{
  int *piVar1;
  int iVar2;
  float10 fVar3;
  
  piVar1 = *(int **)(param_1 + 0x4b4);
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x4b0)) {
    do {
      if (((((char)piVar1[2] != '\0') && (*(char *)((int)piVar1 + 9) != '\0')) && (piVar1[0xb] != 0)
          ) && (*piVar1 != 0xf)) {
        fVar3 = (float10)FUN_004748b0();
        FUN_00569580((float)fVar3);
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x2b;
    } while (iVar2 < *(int *)(param_1 + 0x4b0));
  }
  return;
}


