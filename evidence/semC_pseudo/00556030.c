uint __thiscall FUN_00556030(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  
  cVar1 = FUN_00554b90();
  if (cVar1 != '\0') {
    iVar2 = FUN_00553880();
    iVar3 = FUN_00553860();
    iVar4 = *(int *)(param_1 + 0x58c);
    if (iVar4 < iVar3) {
      iVar4 = FUN_00554920(iVar4 + iVar2,iVar3 - iVar4);
      if (iVar4 < 0) {
        return 0xffffffff;
      }
      if (iVar4 < 1) {
        return 0xffffffff;
      }
      *(int *)(param_1 + 0x58c) = *(int *)(param_1 + 0x58c) + iVar4;
    }
    if (iVar3 <= *(int *)(param_1 + 0x58c)) {
      if (*(ushort *)(param_1 + 0x10) < 0x579) {
        uVar5 = FUN_00553870();
        if ((*(int *)(param_1 + 0x58c) < (int)uVar5) && (cVar1 = FUN_00554b90(), cVar1 != '\0')) {
          iVar4 = FUN_00554920(*(int *)(param_1 + 0x58c) + iVar2,uVar5 - *(int *)(param_1 + 0x58c));
          if (iVar4 < 0) {
            return 0xffffffff;
          }
        }
        else {
          iVar4 = 0;
        }
        uVar8 = *(int *)(param_1 + 0x58c) + iVar4;
        *(uint *)(param_1 + 0x58c) = uVar8;
        if (uVar8 != uVar5) {
          return 0;
        }
        FUN_00553830();
        puVar6 = (undefined4 *)FUN_00553880();
        puVar7 = (undefined4 *)FUN_00553880();
        for (uVar8 = uVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        for (uVar8 = uVar5 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
          *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        if (((*(byte *)(param_2 + 5) & 0x10) != 0) &&
           (cVar1 = FUN_00553a80(*(undefined4 *)(param_1 + 0x5bc)), cVar1 == '\0')) {
          return 0xffffffff;
        }
        if (((*(byte *)(param_2 + 5) & 8) != 0) && (cVar1 = FUN_005539d0(), cVar1 == '\0')) {
          return 0xffffffff;
        }
        if (((*(byte *)(param_2 + 5) & 0x40) == 0) || (cVar1 = FUN_00553b20(), cVar1 != '\0')) {
          *(undefined4 *)(param_1 + 0x58c) = 0;
          FUN_00553830();
          return uVar5;
        }
      }
      return 0xffffffff;
    }
  }
  return 0;
}


