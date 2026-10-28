bool FUN_00412a60(void)

{
  int *piVar1;
  int iVar2;
  int *unaff_EDI;
  undefined4 *puVar3;
  
  puVar3 = &DAT_007e2360;
  for (iVar2 = 0x5d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  DAT_005d5a80 = 0;
  DirectDrawEnumerateA(&LAB_00414f80,0);
  if (unaff_EDI != (int *)0x0) {
    *unaff_EDI = DAT_005d5a80;
  }
  iVar2 = 0;
  if (0 < DAT_005d5a80) {
    piVar1 = &DAT_007e23d4;
    do {
      if ((piVar1[1] != 0) && (*piVar1 != 0)) break;
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x1f;
    } while (iVar2 < DAT_005d5a80);
  }
  return iVar2 != DAT_005d5a80;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// WARNING: Restarted to delay deadcode elimination for space: ram
