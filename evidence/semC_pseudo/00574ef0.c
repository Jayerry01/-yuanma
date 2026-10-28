void __fastcall FUN_00574ef0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_005a5f06;
  local_c = ExceptionList;
  local_4 = 6;
  ExceptionList = &local_c;
  if (param_1 != 0) {
    ExceptionList = &local_c;
    *(undefined4 *)(param_1 + 0x6c) = 0;
    iVar3 = *(int *)(param_1 + 0x70);
    iVar4 = *(int *)(param_1 + 0x74);
    FUN_004a8b00(iVar4,iVar4,iVar3);
    *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + (iVar4 - iVar3 >> 2) * -4;
    iVar3 = *(int *)(param_1 + 0x7c);
    iVar4 = *(int *)(param_1 + 0x80);
    FUN_00576490(iVar4,iVar4,iVar3);
    iVar3 = (int)((ulonglong)((longlong)(iVar4 - iVar3) * -0x2aaaaaab) >> 0x20);
    *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + ((iVar3 >> 1) - (iVar3 >> 0x1f)) * 0xc;
    *(undefined4 *)(param_1 + 0x58) = 0;
    FUN_004f4110(*(undefined4 *)(param_1 + 0x88),*(undefined4 *)(param_1 + 0x8c));
    *(undefined4 *)(param_1 + 0x5c) = 0;
    iVar3 = *(int *)(param_1 + 0x94);
    iVar4 = *(int *)(param_1 + 0x98);
    iVar2 = FUN_005764e0(iVar4,iVar4,iVar3);
    iVar1 = *(int *)(param_1 + 0x98);
    for (; iVar2 != iVar1; iVar2 = iVar2 + 0x68) {
      FUN_00577860(0);
    }
    iVar3 = (int)((ulonglong)((longlong)(iVar4 - iVar3) * -0x4ec4ec4f) >> 0x20);
    *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + ((iVar3 >> 5) - (iVar3 >> 0x1f)) * 0x68;
    *(undefined4 *)(param_1 + 0x60) = 0;
    FUN_00575a50(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xa4));
    *(undefined4 *)(param_1 + 100) = 0;
  }
  iVar3 = (*(int *)(param_1 + 0xa8) - *(int *)(param_1 + 0xa0)) / 0x18;
  local_4._0_1_ = 5;
  if (iVar3 != 0) {
    FUN_00402e90(*(int *)(param_1 + 0xa0),iVar3 * 0x18);
  }
  iVar3 = *(int *)(param_1 + 0x98);
  iVar4 = *(int *)(param_1 + 0x94);
  local_4._0_1_ = 7;
  for (; iVar4 != iVar3; iVar4 = iVar4 + 0x68) {
    FUN_00577860(0);
  }
  iVar3 = *(int *)(param_1 + 0x94);
  iVar4 = (*(int *)(param_1 + 0x9c) - iVar3) / 0x68;
  local_4._0_1_ = 4;
  if (iVar4 != 0) {
    FUN_00402e90(iVar3,iVar4 * 0x68);
  }
  iVar3 = (*(int *)(param_1 + 0x90) - *(int *)(param_1 + 0x88)) / 0xc;
  local_4._0_1_ = 3;
  if (iVar3 != 0) {
    FUN_00402e90(*(int *)(param_1 + 0x88),iVar3 * 0xc);
  }
  iVar3 = (*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c)) / 0xc;
  local_4._0_1_ = 2;
  if (iVar3 != 0) {
    FUN_00402e90(*(int *)(param_1 + 0x7c),iVar3 * 0xc);
  }
  local_4._0_1_ = 1;
  FUN_004fe380();
  iVar3 = *(int *)(param_1 + 0x38);
  iVar4 = *(int *)(param_1 + 0x34);
  local_4._0_1_ = 8;
  for (; iVar4 != iVar3; iVar4 = iVar4 + 0xc) {
    FUN_0047a7e0(0);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0049b270();
  local_4 = 0xffffffff;
  FUN_004fe380();
  ExceptionList = local_c;
  return;
}


