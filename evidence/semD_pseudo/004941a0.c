undefined4 __fastcall FUN_004941a0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  (**(code **)(*param_1 + 0x120))();
  piVar1 = param_1 + 0x8bb;
  if (param_1[0x8bc] != 0) {
    iVar3 = *(int *)(*piVar1 + 4);
    while (iVar3 != 0) {
      FUN_0049d200(*(undefined4 *)(iVar3 + 0xc));
      iVar2 = *(int *)(iVar3 + 8);
      FUN_0048f050();
      FUN_00402e90(iVar3,0x2b8);
      iVar3 = iVar2;
    }
    *(int *)(*piVar1 + 8) = *piVar1;
    *(undefined4 *)(*piVar1 + 4) = 0;
    *(int *)(*piVar1 + 0xc) = *piVar1;
    param_1[0x8bc] = 0;
  }
  return 0;
}


