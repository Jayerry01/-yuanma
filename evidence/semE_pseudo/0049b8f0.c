void __fastcall FUN_0049b8f0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1[1] != 0) {
    iVar2 = *(int *)(*param_1 + 4);
    while (iVar2 != 0) {
      FUN_0049d6e0(*(undefined4 *)(iVar2 + 0xc));
      iVar1 = *(int *)(iVar2 + 8);
      FUN_00402e90(iVar2,0x18);
      iVar2 = iVar1;
    }
    *(int *)(*param_1 + 8) = *param_1;
    *(undefined4 *)(*param_1 + 4) = 0;
    *(int *)(*param_1 + 0xc) = *param_1;
    param_1[1] = 0;
  }
  return;
}


