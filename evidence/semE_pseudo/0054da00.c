void __thiscall FUN_0054da00(int param_1,int param_2)

{
  undefined4 uVar1;
  DWORD DVar2;
  
  *(int *)(param_1 + 0x600) = param_2;
  if (param_2 != 0) {
    uVar1 = FUN_0054f6a0();
    *(undefined4 *)(param_1 + 0x608) = uVar1;
    DVar2 = timeGetTime();
    *(DWORD *)(param_1 + 0x604) = DVar2;
    *(undefined4 *)(param_1 + 0x60c) = 200;
    FUN_00553830();
    DAT_007260b4 = 0x43;
    FUN_00553530(&DAT_007260b0);
  }
  return;
}


