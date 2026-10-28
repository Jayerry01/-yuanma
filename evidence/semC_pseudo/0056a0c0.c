void __fastcall FUN_0056a0c0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_44;
  undefined1 local_40 [64];
  
  local_44 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 0x120) + 0x38)) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x120) + 0x3c) + 0x98;
    do {
      FUN_00477200();
      FUN_00478670(*(undefined4 *)(iVar3 + 0x110),*(undefined4 *)(iVar3 + 0x114),
                   *(undefined4 *)(iVar3 + 0x118),*(undefined4 *)(iVar3 + 0x11c));
      FUN_00477b90(3,iVar3 + 0x120);
      puVar1 = (undefined4 *)FUN_00477ad0(local_40);
      puVar4 = (undefined4 *)(iVar3 + 0x40);
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar4 = puVar4 + 1;
      }
      FUN_00477200();
      local_44 = local_44 + 1;
      iVar3 = iVar3 + 0x2b0;
    } while (local_44 < *(int *)(*(int *)(param_1 + 0x120) + 0x38));
  }
  local_44 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 0x120) + 0x40)) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x120) + 0x44) + 0x98;
    do {
      FUN_00477200();
      FUN_00478670(*(undefined4 *)(iVar3 + 0x110),*(undefined4 *)(iVar3 + 0x114),
                   *(undefined4 *)(iVar3 + 0x118),*(undefined4 *)(iVar3 + 0x11c));
      FUN_00477b90(3,iVar3 + 0x120);
      puVar1 = (undefined4 *)FUN_00477ad0(local_40);
      puVar4 = (undefined4 *)(iVar3 + 0x40);
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar4 = puVar4 + 1;
      }
      FUN_00477200();
      local_44 = local_44 + 1;
      iVar3 = iVar3 + 0x2b0;
    } while (local_44 < *(int *)(*(int *)(param_1 + 0x120) + 0x40));
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x0056a4e1)
// WARNING: Removing unreachable block (ram,0x0056a4e5)
// WARNING: Removing unreachable block (ram,0x0056a4f1)
// WARNING: Removing unreachable block (ram,0x0056a4f3)
// WARNING: Removing unreachable block (ram,0x0056a501)
