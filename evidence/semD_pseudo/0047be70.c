void __thiscall FUN_0047be70(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  
  *(undefined1 *)(param_2 + 0xda) = 0;
  for (puVar1 = (undefined4 *)**(undefined4 **)(param_1 + 0x120);
      (puVar1 != *(undefined4 **)(param_1 + 0x120) && (puVar1[2] != param_2));
      puVar1 = (undefined4 *)*puVar1) {
  }
  if (puVar1[2] == param_2) {
    piVar6 = (int *)**(int **)(param_2 + 0xdc);
    if (piVar6 != *(int **)(param_2 + 0xdc)) {
      uVar5 = FUN_0047bd50();
      do {
        FUN_0047ba50(uVar5);
        piVar6 = (int *)*piVar6;
      } while (piVar6 != (int *)*(int *)(param_2 + 0xdc));
    }
    puVar1 = *(undefined4 **)(param_1 + 0x120);
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
    *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x124) + -1;
  }
  return;
}


