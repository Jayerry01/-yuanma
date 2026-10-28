int FUN_00539d30(int *param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  uint uVar8;
  
  uVar3 = DAT_0072329c;
  DAT_0072329c = param_1;
  iVar2 = FUN_0052e890(param_1,0x80e0,0x1401);
  DAT_0072329c = (int *)uVar3;
  uVar3 = FUN_0052bc40(0x643);
  if (iVar2 == 0) {
    return 0;
  }
  FUN_005395b0(*(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x18),uVar3);
  FUN_00539b30();
  FUN_00539620();
  iVar4 = FUN_00530dc0(0x7c,1);
  if (iVar4 == 0) {
    FUN_0052c1a0(iVar2);
    return 0;
  }
  iVar5 = FUN_00530d80(*(uint *)(iVar2 + 0x18) / 3);
  *(int *)(iVar4 + 0x14) = iVar5;
  if (iVar5 == 0) {
    FUN_0052c1a0(iVar2);
    FUN_00530db0(iVar4);
    return 0;
  }
  FUN_0052cb10(iVar4,param_1);
  *(undefined1 *)(iVar4 + 0xc) = 1;
  iVar5 = *param_1;
  *(int *)(iVar4 + 0x10) = iVar5;
  iVar5 = param_1[1] * iVar5;
  *(int *)(iVar4 + 0x1c) = iVar5;
  *(int *)(iVar4 + 0x18) = iVar5;
  *(undefined4 *)(iVar4 + 0x20) = 0x1900;
  *(undefined4 *)(iVar4 + 0x24) = 0x1401;
  *(undefined4 *)(iVar4 + 0x30) = 0x300;
  *(undefined4 *)(iVar4 + 0x34) = 0x404;
  iVar5 = FUN_00530d80(0x300);
  *(int *)(iVar4 + 0x2c) = iVar5;
  if (iVar5 == 0) {
    FUN_0052c1a0(iVar2);
    FUN_0052c1a0(iVar4);
    return 0;
  }
  iVar5 = 0;
  uVar8 = 0;
  do {
    uVar6 = uVar8 + 0x10;
    *(undefined1 *)(iVar5 + *(int *)(iVar4 + 0x2c)) = *(undefined1 *)((int)&DAT_007232f8 + uVar8);
    *(undefined1 *)(*(int *)(iVar4 + 0x2c) + 1 + iVar5) =
         *(undefined1 *)((int)&DAT_007232fc + uVar8);
    *(undefined1 *)(*(int *)(iVar4 + 0x2c) + 2 + iVar5) =
         *(undefined1 *)((int)&DAT_00723300 + uVar8);
    iVar5 = iVar5 + 3;
    uVar8 = uVar6;
  } while (uVar6 < 0x1000);
  FUN_00539650();
  uVar8 = 0;
  param_1 = (int *)0x0;
  if (*(int *)(iVar2 + 0x18) != 0) {
    do {
      puVar7 = (undefined1 *)(*(int *)(iVar2 + 0x14) + uVar8);
      uVar1 = FUN_00539760(*puVar7,puVar7[1],puVar7[2]);
      uVar8 = uVar8 + 3;
      *(undefined1 *)((int)param_1 + *(int *)(iVar4 + 0x14)) = uVar1;
      param_1 = (int *)((int)param_1 + 1);
    } while (uVar8 < *(uint *)(iVar2 + 0x18));
  }
  FUN_0052c1a0(iVar2);
  return iVar4;
}


