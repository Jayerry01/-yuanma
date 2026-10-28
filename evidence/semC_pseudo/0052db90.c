undefined4 FUN_0052db90(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar3 = FUN_0052c490();
  iVar1 = *(int *)(param_1 + 0x20);
  iVar5 = param_1;
  if (iVar1 == 0x1900) {
    FUN_0052c4a0(param_1);
    uVar6 = *(undefined4 *)(DAT_007232a4 + 0x24);
    uVar4 = FUN_00530fa0(*(undefined4 *)(param_1 + 0x34));
    iVar5 = FUN_0052e890(DAT_007232a4,uVar4,uVar6);
  }
  uVar6 = FUN_00530dc0(1,0x7c);
  cVar2 = FUN_0052cb10(uVar6,iVar5);
  if (cVar2 != '\0') {
    cVar2 = FUN_0052cd50(uVar6,param_2,param_3,param_4,*(undefined1 *)(iVar5 + 0xc),
                         *(undefined1 *)(iVar5 + 0xd));
    if (cVar2 != '\0') {
      if ((param_3 < 2) && (*(uint *)(param_1 + 4) < 2)) {
        FUN_0052dce0(iVar5,uVar6,param_2);
      }
      if ((param_4 < 2) && (*(uint *)(param_1 + 8) < 2)) {
        FUN_00536a30(iVar5,uVar6,param_2,param_3);
      }
      else {
        FUN_00536420(iVar5,uVar6,param_2,param_3,param_4);
      }
      if (iVar1 == 0x1900) {
        FUN_0052c4a0(uVar3);
        FUN_0052c1a0(iVar5);
      }
      return uVar6;
    }
    FUN_0052c1a0(uVar6);
    if (iVar5 != param_1) {
      FUN_0052c1a0(iVar5);
    }
    FUN_0052c4a0(uVar3);
    return 0;
  }
  FUN_0052c1a0(uVar6);
  if (iVar5 != param_1) {
    FUN_0052c1a0(iVar5);
  }
  FUN_0052c4a0(uVar3);
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
