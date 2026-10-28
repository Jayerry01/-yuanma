void __fastcall FUN_0047c100(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStack_44 [15];
  
  puVar2 = (undefined4 *)(param_1 + 0xb0);
  puVar3 = (undefined4 *)register0x00000010;
  for (iVar1 = 0xf; puVar3 = puVar3 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
  }
  puVar3 = auStack_44;
  for (iVar1 = 0xf; register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4), iVar1 != 0;
      iVar1 = iVar1 + -1) {
    *puVar3 = *(undefined4 *)register0x00000010;
    puVar3 = puVar3 + 1;
  }
  FUN_00481970();
  return;
}


