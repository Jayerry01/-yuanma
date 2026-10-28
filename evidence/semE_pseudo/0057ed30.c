void __thiscall FUN_0057ed30(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)(param_1 + 0xd8);
  puVar3 = (undefined4 *)(param_1 + 0x118);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_2 + 0x34);
  *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_2 + 0x38);
  return;
}


