void __thiscall FUN_00553530(int param_1,int param_2)

{
  DWORD DVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 8) != 0) {
    DVar1 = timeGetTime();
    *(DWORD *)(param_1 + 0x5f0) = DVar1;
    *(undefined2 *)(param_2 + 10) = *(undefined2 *)(param_1 + 0x20);
    iVar2 = FUN_00555e00(param_2);
    if (iVar2 < 0) {
      *(undefined1 *)(param_1 + 0xc) = 1;
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
  }
  return;
}


