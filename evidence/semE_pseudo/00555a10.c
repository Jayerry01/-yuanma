void __thiscall FUN_00555a10(int *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if ((int)(param_1[3] + param_3) <= param_1[1] - *param_1) {
    puVar2 = (undefined4 *)(param_1[3] + *param_1);
    for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *param_2 = *puVar2;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
    }
    for (uVar1 = param_3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)param_2 = *(undefined1 *)puVar2;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
    }
    param_1[3] = param_1[3] + param_3;
  }
  return;
}


