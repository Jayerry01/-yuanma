undefined4 * __thiscall FUN_00585940(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a6a38;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_005811c0(param_2,param_3);
  *param_1 = &PTR_FUN_005b10c0;
  iVar6 = 0;
  DAT_0072bcdc = DAT_0072bcdc + 1;
  local_4 = 0;
  param_1[1] = 9;
  param_1[3] = 0x344;
  pcVar3 = (char *)FUN_0058a6d0(9);
  pcVar5 = (char *)(param_1 + 5);
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    *pcVar5 = cVar2;
    pcVar5 = pcVar5 + 1;
  } while (cVar2 != '\0');
  FUN_00581aa0(s_Particle_005d2f28);
  if (param_1[0x7b] != 0) {
    *(undefined1 *)(param_1[0x7b] + 0x29) = 0;
    *(undefined1 *)(param_1[0x7b] + 0x28) = 0;
  }
  param_1[0xa3] = 0;
  param_1[0xa2] = 0;
  param_1[0x9e] = 0x3f000000;
  param_1[0x9f] = 0x3f000000;
  param_1[0x9d] = 0;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  param_1[0xa6] = 0;
  param_1[0xa5] = 0;
  param_1[0xa4] = 0;
  uVar4 = FUN_0056e220();
  param_1[0xaa] = uVar4;
  param_1[0xa9] = uVar4;
  param_1[0xb8] = 3;
  param_1[0xb7] = 3;
  param_1[0x9b] = 0x32;
  param_1[0xbf] = 0x40000000;
  param_1[0xbe] = 0x40000000;
  param_1[0xbd] = 0x40000000;
  param_1[0xbc] = 0x40000000;
  param_1[0xbb] = 0x40000000;
  param_1[199] = 0;
  param_1[0x9c] = 0;
  param_1[0xb9] = 0x40400000;
  param_1[0xba] = 0x3f800000;
  param_1[0xca] = 0xbf800000;
  param_1[0xc9] = 0xbf800000;
  param_1[200] = 0xbf800000;
  param_1[0xcd] = 0x3f800000;
  param_1[0xcc] = 0x3f800000;
  param_1[0xcb] = 0x3f800000;
  param_1[0xce] = 0x3e4ccccd;
  param_1[0xcf] = 0x3e4ccccd;
  param_1[0xd0] = 0x3e4ccccd;
  param_1[0xc1] = 0x41200000;
  param_1[0xc0] = 0x41a00000;
  param_1[0xc2] = 0x3e4ccccd;
  param_1[0xc3] = 0x3ecccccd;
  param_1[0xc4] = 0x43b40000;
  param_1[0xc5] = 0x44340000;
  param_1[0xc6] = 0;
  *(undefined1 *)(param_1 + 0xb3) = 0;
  *(undefined1 *)(param_1 + 0xaf) = 0;
  *(undefined1 *)(param_1 + 0xab) = 0;
  if (DAT_0072bbec == 0) {
    FUN_0047c140(4);
    FUN_0047c1e0(8000,4000,12000);
    FUN_00481b30();
    FUN_00481b30();
    iVar7 = 2;
    param_2 = 1;
    param_3 = 2;
    local_14 = 2000;
    do {
      iVar1 = iVar7 + -2;
      FUN_00481d00(iVar1,0xffffffff);
      FUN_00481d40(iVar1,0,0,0xffffffff);
      FUN_00481d00(iVar7 + -1,0xffffffff);
      FUN_00481d40(iVar7 + -1,0x3f800000,0,0xffffffff);
      FUN_00481d00(iVar7,0xffffffff);
      FUN_00481d40(iVar7,0x3f800000,0x3f800000,0xffffffff);
      FUN_00481d00(iVar7 + 1,0xffffffff);
      FUN_00481d40(iVar7 + 1,0,0x3f800000,0xffffffff);
      FUN_00481ee0(iVar6,iVar1);
      FUN_00481ee0(param_2,iVar7 + -1);
      FUN_00481ee0(param_3,iVar7);
      FUN_00481ee0(iVar6 + 3,iVar1);
      FUN_00481ee0(param_2 + 3,iVar7);
      FUN_00481ee0(param_3 + 3,iVar7 + 1);
      iVar6 = iVar6 + 6;
      param_2 = param_2 + 6;
      param_3 = param_3 + 6;
      iVar7 = iVar7 + 4;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
    FUN_00481b90();
    FUN_00481b90();
  }
  ExceptionList = local_c;
  return param_1;
}


