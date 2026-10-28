undefined1 FUN_00550b00(LPCSTR param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  LSTATUS LVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 uVar7;
  int iVar8;
  undefined4 *puVar9;
  char *pcVar10;
  undefined4 *puVar11;
  HKEY local_8;
  DWORD local_4;
  
  uVar7 = 0;
  local_4 = 0x100;
  LVar3 = RegOpenKeyExA((HKEY)0x80000002,DAT_00725b00,0,1,&local_8);
  if (LVar3 == 0) {
    LVar3 = RegQueryValueExA(local_8,param_1,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&DAT_007259f0,
                             &local_4);
    uVar7 = 0;
    if (LVar3 == 0) {
      uVar5 = 0xffffffff;
      pcVar10 = (char *)&DAT_007259f0;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      puVar11 = (undefined4 *)*param_2;
      uVar6 = param_2[1] - (int)puVar11;
      uVar4 = ~uVar5 - 1;
      if (uVar6 < uVar4) {
        puVar9 = &DAT_007259f0;
        for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar11 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar11 = puVar11 + 1;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
          puVar9 = (undefined4 *)((int)puVar9 + 1);
          puVar11 = (undefined4 *)((int)puVar11 + 1);
        }
        FUN_00403490((int)&DAT_007259f0 + (param_2[1] - *param_2),~uVar5 + 0x7259ef);
      }
      else {
        puVar9 = &DAT_007259f0;
        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar11 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar11 = puVar11 + 1;
        }
        for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
          puVar9 = (undefined4 *)((int)puVar9 + 1);
          puVar11 = (undefined4 *)((int)puVar11 + 1);
        }
        iVar2 = param_2[1];
        iVar8 = *param_2 + uVar4;
        if (iVar8 != iVar2) {
          FUN_005092c0(iVar8,iVar2,1);
          param_2[1] = param_2[1] + (iVar8 - iVar2);
        }
      }
      uVar7 = 1;
    }
    RegCloseKey(local_8);
  }
  return uVar7;
}


