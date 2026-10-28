undefined4 FUN_00410f60(HINSTANCE param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  LPSTR pCVar8;
  int iVar9;
  WNDCLASSEXA local_30;
  
  DAT_005d5a44 = param_1;
  DAT_005d5a74 = 0;
  DAT_007e0e90 = 0;
  DAT_007e2bd8 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
  DAT_007e2be0 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  DAT_007e2304 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f03);
  local_30.style = 0x2b;
  local_30.lpfnWndProc = (WNDPROC)&LAB_00411190;
  local_30.cbClsExtra = 0;
  local_30.cbWndExtra = 0;
  local_30.hInstance = param_1;
  local_30.hIcon = LoadIconA(param_1,(LPCSTR)0x1);
  local_30.hCursor = (HCURSOR)0x0;
  DAT_005d5a6c = CreateSolidBrush(0);
  local_30.lpszMenuName = (LPCSTR)0x0;
  local_30.lpszClassName = s_Lz3DCWANG_005c4588;
  local_30.cbSize = 0x30;
  local_30.hIconSm = (HICON)0x0;
  local_30.hbrBackground = DAT_005d5a6c;
  RegisterClassExA(&local_30);
  pcVar2 = GetCommandLineA();
  uVar6 = 0xffffffff;
  pCVar8 = pcVar2;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pCVar8;
    pCVar8 = pCVar8 + 1;
  } while (cVar1 != '\0');
  puVar3 = _malloc(~uVar6);
  uVar6 = 0xffffffff;
  pCVar8 = pcVar2;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pCVar8;
    pCVar8 = pCVar8 + 1;
  } while (cVar1 != '\0');
  puVar5 = puVar3;
  for (uVar7 = ~uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  for (uVar6 = ~uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  iVar9 = (int)puVar3 - (int)pcVar2;
  do {
    cVar1 = *pcVar2;
    pcVar2[iVar9] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar4 = (char *)FUN_0050a22f(puVar3,&DAT_005c462c);
  uVar6 = 0xffffffff;
  DAT_005d5a40 = 1;
  pcVar2 = pcVar4;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = _malloc(~uVar6);
  DAT_007e2c00 = pcVar2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar2 = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = (char *)FUN_0050a22f(0,&DAT_005c462c);
  do {
    if (pcVar2 == (char *)0x0) {
      FUN_004010f0(DAT_005d5a40,&DAT_007e2c00);
      if (DAT_005d5a44 != (HINSTANCE)0x0) {
        UnregisterClassA(s_Lz3DCWANG_005c4588,DAT_005d5a44);
        DAT_005d5a44 = (HINSTANCE)0x0;
      }
      iVar9 = 0;
      if (0 < DAT_005d5a40) {
        do {
          FUN_005089fd((&DAT_007e2c00)[iVar9]);
          iVar9 = iVar9 + 1;
        } while (iVar9 < DAT_005d5a40);
      }
      FUN_005089fd(puVar3);
      return 0;
    }
    uVar6 = 0xffffffff;
    pcVar4 = pcVar2;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    puVar5 = _malloc(~uVar6);
    uVar6 = 0xffffffff;
    (&DAT_007e2c00)[DAT_005d5a40] = (char *)puVar5;
    pcVar4 = pcVar2;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    for (uVar7 = ~uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    for (uVar6 = ~uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar5 = 0;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    pcVar4 = (&DAT_007e2c00)[DAT_005d5a40];
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    DAT_005d5a40 = DAT_005d5a40 + 1;
    pcVar2 = (char *)FUN_0050a22f(0,&DAT_005c462c);
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
