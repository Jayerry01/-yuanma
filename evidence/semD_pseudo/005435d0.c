void FUN_005435d0(int param_1,int param_2,int *param_3,undefined4 param_4,int param_5,int *param_6,
                 int param_7)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar3 = param_1;
  iVar2 = *(int *)(param_1 + 0x1a0);
  if (*(int *)(param_1 + 0x114) <= *(int *)(iVar2 + 0x5c)) {
    piVar1 = (int *)(param_1 + 0x24);
    param_1 = *(int *)(param_1 + 0xc4);
    iVar5 = 0;
    if (0 < *piVar1) {
      iVar6 = iVar2 + 0xc;
      do {
        (**(code **)(iVar6 + 0x28))
                  (iVar3,param_1,
                   *(int *)(param_2 + iVar5 * 4) + *(int *)(iVar6 + 0x58) * *param_3 * 4,iVar6);
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 4;
        param_1 = param_1 + 0x54;
      } while (iVar5 < *(int *)(iVar3 + 0x24));
    }
    *(undefined4 *)(iVar2 + 0x5c) = 0;
  }
  uVar7 = *(int *)(iVar3 + 0x114) - *(int *)(iVar2 + 0x5c);
  if (*(uint *)(iVar2 + 0x60) < uVar7) {
    uVar7 = *(uint *)(iVar2 + 0x60);
  }
  uVar4 = param_7 - *param_6;
  if (uVar4 < uVar7) {
    uVar7 = uVar4;
  }
  (**(code **)(*(int *)(iVar3 + 0x1a4) + 4))
            (iVar3,iVar2 + 0xc,*(undefined4 *)(iVar2 + 0x5c),param_5 + *param_6 * 4,uVar7);
  *param_6 = *param_6 + uVar7;
  iVar5 = *(int *)(iVar2 + 0x5c) + uVar7;
  *(uint *)(iVar2 + 0x60) = *(int *)(iVar2 + 0x60) - uVar7;
  *(int *)(iVar2 + 0x5c) = iVar5;
  if (*(int *)(iVar3 + 0x114) <= iVar5) {
    *param_3 = *param_3 + 1;
  }
  return;
}


