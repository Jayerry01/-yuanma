void __fastcall FUN_00481970(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = &stack0x00000004;
  puVar3 = (undefined4 *)(param_1 + 0x10);
  for (iVar2 = 0xf; register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4), iVar2 != 0;
      iVar2 = iVar2 + -1) {
    *puVar3 = *(undefined4 *)register0x00000010;
    puVar3 = puVar3 + 1;
  }
  FUN_00474e60(puVar1);
  return;
}


