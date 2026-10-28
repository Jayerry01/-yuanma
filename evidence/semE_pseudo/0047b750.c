void __fastcall FUN_0047b750(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_40 [64];
  
  if (*(int *)(param_1 + 0xd4) == 0) {
    puVar1 = (undefined4 *)(param_1 + 0x14);
  }
  else {
    FUN_0047b750();
    puVar1 = (undefined4 *)FUN_00476f00(local_40,param_1 + 0x14,*(int *)(param_1 + 0xd4) + 0x54);
  }
  puVar3 = (undefined4 *)(param_1 + 0x54);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(param_1 + 0xe0) = 0;
  return;
}


