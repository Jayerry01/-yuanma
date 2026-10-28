void __fastcall FUN_0047bda0(int param_1)

{
  int *piVar1;
  
  FUN_0047ba90();
  piVar1 = (int *)**(int **)(param_1 + 0x120);
  if (piVar1 != *(int **)(param_1 + 0x120)) {
    do {
      if (*(int *)(piVar1[2] + 0xd4) == 0) {
        FUN_0047b750();
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0x120));
  }
  return;
}


