void __fastcall FUN_0047de20(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 local_c [12];
  
  puVar1 = (undefined4 *)FUN_00481b30();
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      puVar2 = (undefined4 *)FUN_00476e80(local_c,puVar1,&stack0x00000004);
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      puVar1[2] = puVar2[2];
      puVar1 = (undefined4 *)((int)puVar1 + *(int *)(param_1 + 0xb0));
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 4));
  }
  FUN_00481b90();
  return;
}


