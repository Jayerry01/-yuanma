void __thiscall FUN_0055df80(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)(param_1 + 0x658);
  puVar2 = (undefined4 *)*puVar1;
  while (puVar4 = puVar2, puVar4 != puVar1) {
    puVar2 = (undefined4 *)*puVar4;
    if (puVar4[2] == param_2) {
      puVar3 = (undefined4 *)puVar4[1];
      *puVar3 = puVar2;
      puVar2[1] = puVar3;
      FUN_00402e90(puVar4,0xc);
    }
  }
  return;
}


