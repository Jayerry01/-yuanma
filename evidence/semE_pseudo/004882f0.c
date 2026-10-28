void __fastcall FUN_004882f0(int param_1)

{
  int *piVar1;
  
  (**(code **)(*(int *)(param_1 + 0x2488) + 0x104))();
  piVar1 = (int *)**(int **)(param_1 + 0x2960);
  if (piVar1 != *(int **)(param_1 + 0x2960)) {
    do {
      (**(code **)(*(int *)piVar1[2] + 0x104))();
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0x2960));
  }
  return;
}



undefined4 __thiscall