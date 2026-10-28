void __fastcall FUN_00573650(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    FUN_00507850(*(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    FUN_00507850(*(int *)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x2c);
  if (iVar1 != 0) {
    FUN_0050ace3(iVar1,0xac,*(undefined4 *)(iVar1 + -4),&LAB_00571df0);
    FUN_00507850(iVar1 + -4);
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 != 0) {
    FUN_0050ace3(iVar1,0x2c,*(undefined4 *)(iVar1 + -4),FUN_00571cb0);
    FUN_00507850(iVar1 + -4);
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    FUN_00507850(*(int *)(param_1 + 0x24));
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x34);
  if (iVar1 != 0) {
    FUN_0050ace3(iVar1,4,*(undefined4 *)(iVar1 + -4),FUN_0057d910);
    FUN_00507850(iVar1 + -4);
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  return;
}


