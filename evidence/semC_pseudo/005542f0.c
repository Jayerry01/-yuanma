uint __thiscall FUN_005542f0(int param_1,uint param_2)

{
  DWORD DVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_c;
  uint local_8;
  
  uVar2 = *(uint *)(param_1 + 0x3c);
  if (uVar2 != *(uint *)(param_1 + 0x2c)) {
    DVar1 = timeGetTime();
    uVar2 = DVar1 - *(int *)(param_1 + 0x18);
    if (500 < uVar2) {
      local_c = 0;
      for (local_8 = 0; iVar5 = *(int *)(param_1 + 0x3c) - *(int *)(param_1 + 0x40),
          uVar2 = iVar5 * 0x2aaaaaab,
          local_8 < (iVar5 / 0x18 +
                    (*(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x2c)) / 0x18 +
                    (*(int *)(param_1 + 0x48) - *(int *)(param_1 + 0x38) >> 2) * 0x15) - 0x15U;
          local_8 = local_8 + 1) {
        iVar5 = (*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x30)) / 0x18 + local_8;
        if ((iVar5 < 0) || (0x14 < iVar5)) {
          if (iVar5 < 1) {
            iVar3 = -1 - (-iVar5 - 1U) / 0x15;
          }
          else {
            iVar3 = iVar5 / 0x15;
          }
          iVar5 = *(int *)(*(int *)(param_1 + 0x38) + iVar3 * 4) + (iVar5 + iVar3 * -0x15) * 0x18;
        }
        else {
          iVar5 = *(int *)(param_1 + 0x2c) + local_c;
        }
        if (DVar1 - *(int *)(iVar5 + 0xc) < param_2) {
          return param_2;
        }
        *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + 1;
        *(uint *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + (uint)*(ushort *)(iVar5 + 0x10);
        if (*(float *)(param_1 + 0x20) <= 0.0) {
LAB_0055445a:
          uVar2 = FUN_005547a0(*(undefined4 *)(iVar5 + 0x14),*(undefined2 *)(iVar5 + 0x10),iVar5 + 4
                              );
          if ((int)uVar2 < 1) {
            return uVar2;
          }
          *(DWORD *)(param_1 + 0x18) = DVar1;
        }
        else {
          iVar3 = _rand();
          iVar4 = __ftol();
          if (iVar4 <= iVar3 % 1000) goto LAB_0055445a;
        }
        local_c = local_c + 0x18;
      }
    }
  }
  return uVar2;
}


