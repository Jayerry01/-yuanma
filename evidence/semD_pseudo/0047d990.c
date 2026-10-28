void __thiscall FUN_0047d990(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_4;
  
  local_4 = (int)(*(int *)(param_1 + 4) + (*(int *)(param_1 + 4) >> 0x1f & 3U)) >> 2;
  iVar1 = local_4 * 2;
  FUN_00481b30();
  if (0 < local_4) {
    iVar5 = 2;
    iVar4 = local_4 * 0xff;
    do {
      uVar2 = FUN_00475c50(param_2,param_3,param_4,iVar4 / iVar1);
      iVar4 = iVar4 + -0xff;
      uVar3 = FUN_00475c50(param_2,param_3,param_4,iVar4 / iVar1);
      FUN_00481d00(iVar5 + -2,uVar2);
      FUN_00481d00(iVar5 + -1,uVar3);
      FUN_00481d00(iVar5,uVar3);
      FUN_00481d00(iVar5 + 1,uVar2);
      iVar5 = iVar5 + 4;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  FUN_00481b90();
  return;
}


