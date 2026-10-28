undefined4 __thiscall FUN_00488180(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x2144) == 0) {
    iVar2 = (**(code **)(*(int *)(param_1 + 0x2488) + 0x1d0))(param_2);
    if (iVar2 != 0) {
      return 1;
    }
    for (puVar1 = (undefined4 *)**(undefined4 **)(param_1 + 0x2960);
        puVar1 != *(undefined4 **)(param_1 + 0x2960); puVar1 = (undefined4 *)*puVar1) {
      if (*(int *)(puVar1[2] + 0x254) == param_2) {
        return 1;
      }
    }
  }
  return 0;
}


