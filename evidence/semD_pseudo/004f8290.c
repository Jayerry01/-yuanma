void __thiscall FUN_004f8290(int param_1,int *param_2)

{
  ushort *puVar1;
  uint *puVar2;
  int *piVar3;
  
  piVar3 = param_2;
  param_2[1] = param_2[1] + (param_2[1] - *param_2 >> 2) * -4;
  for (puVar1 = (ushort *)(param_1 + 0x1c); puVar1 != (ushort *)0x0;
      puVar1 = *(ushort **)(puVar1 + 8)) {
    puVar2 = (uint *)piVar3[1];
    param_2 = (int *)(uint)*puVar1;
    if (puVar2 == (uint *)piVar3[2]) {
      FUN_0046ecb0(puVar2,&param_2);
    }
    else {
      if (puVar2 != (uint *)0x0) {
        *puVar2 = (uint)param_2;
      }
      piVar3[1] = piVar3[1] + 4;
    }
  }
  return;
}


