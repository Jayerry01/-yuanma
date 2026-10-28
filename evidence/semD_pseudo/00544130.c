void FUN_00544130(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x30);
  *(undefined4 **)(param_1 + 0x1a0) = puVar1;
  *puVar1 = &LAB_00544280;
  *(undefined1 *)(puVar1 + 2) = 0;
  puVar1[10] = *(int *)(param_1 + 100) * *(int *)(param_1 + 0x5c);
  if (*(int *)(param_1 + 0x114) == 2) {
    puVar1[1] = &LAB_005442a0;
    puVar1[3] = &DAT_00544510;
    uVar2 = (**(code **)(*(int *)(param_1 + 4) + 4))(param_1,1,puVar1[10]);
    puVar1[8] = uVar2;
    FUN_005441c0(param_1);
    return;
  }
  puVar1[1] = FUN_00544370;
  puVar1[3] = &LAB_005443b0;
  puVar1[8] = 0;
  FUN_005441c0(param_1);
  return;
}


