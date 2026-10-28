void __thiscall FUN_0056d830(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_40 [16];
  
  FUN_00477200();
  if (param_3 == 0) {
    if ((param_4 < 0) || (*(int *)(param_1 + 0x214) <= param_4)) goto LAB_0056d8a5;
    iVar2 = *(int *)(param_1 + 0x228);
  }
  else if (param_3 == 1) {
    if ((param_4 < 0) || (*(int *)(param_1 + 0x218) <= param_4)) goto LAB_0056d8a5;
    iVar2 = *(int *)(param_1 + 0x234);
  }
  else {
    if (((param_3 != 2) || (param_4 < 0)) || (*(int *)(param_1 + 0x21c) <= param_4))
    goto LAB_0056d8a5;
    iVar2 = *(int *)(param_1 + 0x240);
  }
  puVar3 = (undefined4 *)(iVar2 + param_4 * 0x40);
  puVar4 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
LAB_0056d8a5:
  puVar3 = local_40;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_2 = *puVar3;
    puVar3 = puVar3 + 1;
    param_2 = param_2 + 1;
  }
  return;
}


