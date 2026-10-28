void __thiscall FUN_0054b150(int param_1,int param_2)

{
  DWORD DVar1;
  int iVar2;
  DWORD *pDVar3;
  DWORD *pDVar4;
  DWORD local_24 [6];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a4568;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x14) != 0) {
    ExceptionList = &local_c;
    *(undefined2 *)(param_2 + 10) = *(undefined2 *)(param_1 + 0x10);
    DVar1 = timeGetTime();
    *(DWORD *)(param_1 + 0xd8) = DVar1;
    if (*(char *)(param_1 + 0xf8) != '\0') {
      FUN_00554c90();
      local_24[1] = *(undefined4 *)(param_1 + 4);
      local_24[2] = *(undefined4 *)(param_1 + 8);
      local_4 = 0;
      local_24[3] = timeGetTime();
      FUN_00554cd0(param_2);
      pDVar4 = *(DWORD **)(param_1 + 0x13c);
      if (pDVar4 == (DWORD *)(*(int *)(param_1 + 0x144) + -0x18)) {
        FUN_0054c510(local_24);
      }
      else {
        if (pDVar4 != (DWORD *)0x0) {
          pDVar3 = local_24;
          for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
            *pDVar4 = *pDVar3;
            pDVar3 = pDVar3 + 1;
            pDVar4 = pDVar4 + 1;
          }
        }
        *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x13c) + 0x18;
      }
      local_4 = 0xffffffff;
      FUN_004e8500();
      ExceptionList = local_c;
      return;
    }
    iVar2 = FUN_00553de0(param_2,param_1 + 4);
    if (iVar2 < 0) {
      *(undefined1 *)(param_1 + 0x1c) = 1;
      *(undefined4 *)(param_1 + 0x20) = 0;
    }
  }
  ExceptionList = local_c;
  return;
}


