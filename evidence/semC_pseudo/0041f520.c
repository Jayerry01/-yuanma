int * FUN_0041f520(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *unaff_EDI;
  undefined4 *puVar4;
  undefined1 *puStack_114;
  int *piStack_110;
  undefined1 local_100 [8];
  undefined4 local_f8 [16];
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0 [7];
  undefined1 auStack_94 [4];
  int local_90;
  undefined4 local_8c [35];
  
  puVar3 = local_f8;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_f8[0] = 0x7c;
  local_f8[1] = 0x101007;
  if (param_4 != 0) {
    local_f8[1] = 0x111007;
    local_b8 = param_5;
    local_b4 = param_5;
  }
  local_f8[3] = param_1;
  local_f8[2] = param_2;
  local_90 = (-(uint)(param_3 != 0) & 0x4005800) + 0x1800;
  local_8c[0] = 0;
  puStack_114 = local_100;
  puVar3 = &DAT_007e22e0;
  puVar4 = local_b0;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  piStack_110 = (int *)0x0;
  iVar2 = (**(code **)(**(int **)(DAT_005d5a0c + 0x6ec) + 0x18))
                    (*(int **)(DAT_005d5a0c + 0x6ec),local_f8);
  if (-1 < iVar2) {
    if (param_3 == 0) {
      return piStack_110;
    }
    puVar3 = local_8c;
    for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    local_8c[0] = 0x7c;
    (**(code **)(**(int **)(DAT_005d5a0c + 0x764) + 0x58))(*(int **)(DAT_005d5a0c + 0x764),local_8c)
    ;
    iVar2 = (**(code **)(**(int **)(DAT_005d5a0c + 0x6ec) + 0x18))
                      (*(int **)(DAT_005d5a0c + 0x6ec),auStack_94,&puStack_114,0);
    piVar1 = piStack_110;
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*piStack_110 + 0xc))(piStack_110,unaff_EDI);
      if (-1 < iVar2) {
        return piStack_110;
      }
      piVar1 = unaff_EDI;
      if (piStack_110 != (int *)0x0) {
        (**(code **)(*piStack_110 + 8))(piStack_110);
        piStack_110 = (int *)0x0;
      }
    }
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return (int *)0x0;
}


