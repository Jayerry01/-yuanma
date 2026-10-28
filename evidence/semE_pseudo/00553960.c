void __thiscall FUN_00553960(int *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if ((int)(*param_1 + param_3) < 0x579) {
    puVar2 = (undefined4 *)(*param_1 + 0xe + (int)param_1);
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
    *param_1 = *param_1 + param_3;
  }
  return;
}


