void __thiscall FUN_004bd400(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_4;
  
  local_4 = param_2;
  FUN_0049d3c0(&param_2,&local_4);
  if (param_2 != *(int *)(param_1 + 0x398)) {
    if (*(int *)(param_1 + 0x390) == 0) {
      uVar2 = *(undefined4 *)(param_2 + 0x244);
      FUN_004b3420(uVar2);
      FUN_0054d9b0(uVar2);
    }
    iVar1 = *(int *)(param_1 + 0x398);
    uVar2 = FUN_0048ea60(param_2,iVar1 + 4,iVar1 + 8,iVar1 + 0xc);
    FUN_0048f050();
    FUN_00402e90(uVar2,0x2b8);
    *(int *)(param_1 + 0x39c) = *(int *)(param_1 + 0x39c) + -1;
  }
  return;
}


