void __fastcall FUN_004f7d30(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2 != 0) {
    do {
      FUN_00507850(*(undefined4 *)(*(int *)(param_1 + 4) + uVar3 * 4));
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2));
  }
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(param_1 + 8);
  FUN_0049f3d0(iVar2,iVar2,iVar1,param_1,0);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + (iVar2 - iVar1 >> 2) * -4;
  uVar3 = 0;
  if (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10) >> 2 != 0) {
    do {
      FUN_00507850(*(undefined4 *)(*(int *)(param_1 + 0x10) + uVar3 * 4));
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)(*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10) >> 2));
  }
  *(int *)(param_1 + 0x14) =
       *(int *)(param_1 + 0x14) + (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10) >> 2) * -4;
  return;
}



undefined4 __thiscall