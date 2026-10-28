void FUN_00555800(int param_1,int param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if (param_3 != (undefined1 *)0x0) {
    puVar1 = (undefined1 *)(param_1 + 1);
    puVar2 = (undefined1 *)(param_2 + 2);
    do {
      puVar1[-1] = puVar2[-2];
      *puVar1 = puVar2[-1];
      puVar1[1] = *puVar2;
      puVar1[2] = puVar2[1];
      puVar1 = puVar1 + 4;
      puVar2 = puVar2 + 4;
    } while (puVar1 + (-1 - param_1) < param_3);
  }
  return;
}


