void __fastcall FUN_00584180(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  char *pcVar10;
  undefined4 *puVar11;
  int local_4;
  
  if (*(int *)(param_1 + 0x274) != 0) {
    iVar7 = 0;
    iVar2 = FUN_005565e0();
    if (0 < iVar2) {
      do {
        (**(code **)(**(int **)(param_1 + 0x274) + 0x18))(iVar7,0);
        iVar7 = iVar7 + 1;
        iVar2 = FUN_005565e0();
      } while (iVar7 < iVar2);
    }
  }
  local_4 = 0;
  if (*(int *)(param_1 + 0x91c) < 1) {
    *(undefined4 *)(param_1 + 0x91c) = 0;
    return;
  }
  piVar8 = (int *)(param_1 + 0x278);
  piVar6 = (int *)(param_1 + 0x8e0);
  do {
    if ((int *)*piVar8 != (int *)0x0) {
      (**(code **)(*(int *)*piVar8 + 8))(1);
      *piVar8 = 0;
    }
    uVar4 = 0xffffffff;
    pcVar10 = (char *)&DAT_005d5a24;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    puVar11 = (undefined4 *)*piVar6;
    uVar5 = piVar6[1] - (int)puVar11;
    uVar3 = ~uVar4 - 1;
    if (uVar5 < uVar3) {
      puVar9 = &DAT_005d5a24;
      for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar11 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar11 = puVar11 + 1;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      FUN_00403490((int)&DAT_005d5a24 + (piVar6[1] - *piVar6),~uVar4 + 0x5d5a23);
    }
    else {
      puVar9 = &DAT_005d5a24;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar11 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar11 = puVar11 + 1;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      iVar2 = piVar6[1];
      iVar7 = *piVar6 + uVar3;
      if (iVar7 != iVar2) {
        FUN_005092c0(iVar7,iVar2,1);
        piVar6[1] = piVar6[1] + (iVar7 - iVar2);
      }
    }
    local_4 = local_4 + 1;
    piVar8 = piVar8 + 1;
    piVar6 = piVar6 + 3;
    if (*(int *)(param_1 + 0x91c) <= local_4) {
      *(undefined4 *)(param_1 + 0x91c) = 0;
      return;
    }
  } while( true );
}



// WARNING: Removing unreachable block (ram,0x00584796)
// WARNING: Removing unreachable block (ram,0x0058476f)
// WARNING: Removing unreachable block (ram,0x0058474b)
// WARNING: Removing unreachable block (ram,0x005845fc)
// WARNING: Removing unreachable block (ram,0x00584600)
// WARNING: Removing unreachable block (ram,0x00584612)
// WARNING: Removing unreachable block (ram,0x00584607)
// WARNING: Removing unreachable block (ram,0x005846d9)
// WARNING: Removing unreachable block (ram,0x005846e1)
// WARNING: Removing unreachable block (ram,0x005847a8)
// WARNING: Removing unreachable block (ram,0x005846ec)
// WARNING: Removing unreachable block (ram,0x0058474f)
// WARNING: Removing unreachable block (ram,0x00584773)
// WARNING: Removing unreachable block (ram,0x0058479a)
// WARNING: Removing unreachable block (ram,0x00584653)
// WARNING: Removing unreachable block (ram,0x00584657)
// WARNING: Removing unreachable block (ram,0x00584669)
// WARNING: Removing unreachable block (ram,0x0058465e)
// WARNING: Globals starting with '_' overlap smaller symbols at the same address
