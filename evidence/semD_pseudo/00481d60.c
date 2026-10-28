FUN_00481d60(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            int param_6)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  if ((((*(int *)(param_1 + 0xc) != 0) && (-1 < param_2)) && (param_2 < *(int *)(param_1 + 0x4c)))
     && (*(int *)(param_1 + 0x24) != -1)) {
    puVar2 = (undefined4 *)
             (*(int *)(param_1 + 0x10) * param_2 + *(int *)(param_1 + 0x24) +
             *(int *)(param_1 + 0xc));
    if (param_6 == -1) {
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x28)) {
        piVar3 = (int *)(param_1 + 0x2c);
        do {
          if (0 < *piVar3) {
            *puVar2 = param_3;
            puVar2 = puVar2 + 1;
          }
          if (1 < *piVar3) {
            *puVar2 = param_4;
            puVar2 = puVar2 + 1;
          }
          if (2 < *piVar3) {
            *puVar2 = param_5;
            puVar2 = puVar2 + 1;
          }
          if (3 < *piVar3) {
            *puVar2 = 0x3f800000;
            puVar2 = puVar2 + 1;
          }
          iVar4 = iVar4 + 1;
          piVar3 = piVar3 + 1;
        } while (iVar4 < *(int *)(param_1 + 0x28));
        return 1;
      }
    }
    else {
      if (0 < param_6) {
        piVar3 = (int *)(param_1 + 0x2c);
        iVar4 = param_6;
        do {
          iVar1 = *piVar3;
          piVar3 = piVar3 + 1;
          iVar4 = iVar4 + -1;
          puVar2 = puVar2 + iVar1;
        } while (iVar4 != 0);
      }
      if (0 < *(int *)(param_1 + 0x2c + param_6 * 4)) {
        *puVar2 = param_3;
        puVar2 = puVar2 + 1;
      }
      if (1 < *(int *)(param_1 + 0x2c + param_6 * 4)) {
        *puVar2 = param_4;
        puVar2 = puVar2 + 1;
      }
      if (2 < *(int *)(param_1 + 0x2c + param_6 * 4)) {
        *puVar2 = param_5;
        puVar2 = puVar2 + 1;
      }
      if (3 < *(int *)(param_1 + 0x2c + param_6 * 4)) {
        *puVar2 = 0x3f800000;
      }
    }
    return 1;
  }
  return 0;
}



undefined4 __thiscall