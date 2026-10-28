undefined4 FUN_00415490(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 *puVar4;
  undefined4 unaff_retaddr;
  
  piVar1 = (int *)(param_2 + 0x30);
  DAT_007e2768 = (**(code **)(**(int **)(param_1 + 0x75c) + 0x18))
                           (*(int **)(param_1 + 0x75c),piVar1,0);
  if (DAT_007e2768 != 0) {
    *piVar1 = 0;
    return 0;
  }
  DAT_007e2768 = (**(code **)(**(int **)(param_1 + 0x760) + 0x14))
                           (*(int **)(param_1 + 0x760),*piVar1);
  if (DAT_007e2768 != 0) {
    piVar2 = (int *)*piVar1;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *piVar1 = 0;
    }
    return 0;
  }
  FUN_004153e0(param_2,unaff_EBP,unaff_EBX,unaff_retaddr,param_1,0);
  *(undefined4 *)(param_2 + 0x28) = 0;
  *(undefined4 *)(param_2 + 0x24) = 0;
  *(undefined4 *)(param_2 + 0x20) = 0;
  FUN_004155c0(param_2,0,0,0);
  puVar4 = (undefined4 *)(param_2 + 0x128);
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)(param_2 + 0x34) = 0;
  return 1;
}



undefined4