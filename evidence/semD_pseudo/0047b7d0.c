FUN_0047b7d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  if (param_5 != 0) {
    FUN_004781d0(param_2,param_3,param_4,0);
    *(undefined4 *)(param_1 + 0xe0) = 1;
    return;
  }
  FUN_00477200();
  FUN_004781d0(param_2,param_3,param_4,0);
  puVar1 = (undefined4 *)FUN_00476f00(local_40,(undefined4 *)(param_1 + 0x14),local_80);
  puVar3 = (undefined4 *)(param_1 + 0x14);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(param_1 + 0xe0) = 1;
  return;
}


