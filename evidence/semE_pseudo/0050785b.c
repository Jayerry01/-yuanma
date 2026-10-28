undefined4 * __fastcall FUN_0050785b(undefined4 *param_1)

{
  int iVar1;
  
  param_1[0xd] = 0xffffffff;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0xc] = 0;
  param_1[7] = 0;
  *param_1 = &PTR_FUN_005ac348;
  param_1[2] = 4;
  param_1[10] = 6;
  *(undefined1 *)(param_1 + 0xb) = 0x20;
  FUN_00507fff(param_1 + 0xe);
  iVar1 = DAT_00667628;
  DAT_00667628 = DAT_00667628 + 1;
  if (iVar1 == 0) {
    FUN_00507fff(&DAT_006675f0);
  }
  return param_1;
}


