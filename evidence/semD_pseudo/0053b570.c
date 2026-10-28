void FUN_0053b570(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    iVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x24);
    *(int *)(param_1 + 0x18) = iVar2;
    uVar3 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x1000);
    *(undefined4 *)(iVar2 + 0x1c) = uVar3;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  puVar1[2] = &LAB_0053b5e0;
  puVar1[3] = FUN_0053b5f0;
  puVar1[4] = FUN_0053b650;
  puVar1[5] = FUN_0053c270;
  puVar1[6] = FUN_00544120;
  puVar1[1] = 0;
  *puVar1 = 0;
  return;
}


