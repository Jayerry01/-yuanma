void FUN_005395b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  DAT_0072c660 = param_1;
  DAT_0072c668 = param_2;
  iVar2 = 0;
  puVar5 = &DAT_0072c680;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  DAT_0072c664 = param_3;
  puVar5 = &DAT_0072c260;
  for (iVar1 = 0x100; piVar3 = &DAT_007232fc, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = 0x100;
    puVar5 = puVar5 + 1;
  }
  do {
    piVar4 = piVar3 + 4;
    iVar1 = (int)(iVar2 * 0x1000 + (iVar2 * 0x1000 >> 0x1f & 0xffU)) >> 8;
    piVar3[1] = iVar1;
    *piVar3 = iVar1;
    piVar3[-1] = iVar1;
    iVar2 = iVar2 + 1;
    piVar3 = piVar4;
  } while ((int)piVar4 < 0x7242fc);
  return;
}


