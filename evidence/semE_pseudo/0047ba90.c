void __fastcall FUN_0047ba90(int param_1)

{
  int *piVar1;
  
  FUN_0047b750();
  piVar1 = (int *)**(int **)(param_1 + 0xdc);
  if (piVar1 != *(int **)(param_1 + 0xdc)) {
    do {
      FUN_0047ba90();
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0xdc));
  }
  return;
}


