int __thiscall FUN_004c0580(int param_1,uint param_2,undefined4 param_3)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iStack_4;
  
  iStack_4 = param_1;
  iVar4 = FUN_00487830();
  piVar1 = *(int **)(iVar4 + 0x212c);
  if (piVar1 != (int *)0x0) {
    uVar5 = (**(code **)(*(int *)(iVar4 + 0x2488) + 0x4c))();
    uVar2 = param_2;
    if ((param_2 == uVar5) && (iVar4 = FUN_004c38e0(), (char)iVar4 == '\0')) {
      return iVar4;
    }
    iVar6 = (**(code **)(*piVar1 + 0x3c))();
    iVar4 = 0;
    if ((iVar6 != 0) &&
       (param_2 = uVar2, FUN_0049d3c0(&iStack_4,&param_2), uVar3 = param_3, iVar4 = iStack_4,
       iStack_4 != *(int *)(iVar6 + 4))) {
      piVar1 = (int *)(iStack_4 + 0x88);
      (**(code **)(*(int *)(iStack_4 + 0x88) + 0x28))(2,param_3);
      iVar4 = (**(code **)(*piVar1 + 0x28))(1,uVar3);
      if ((-1 < (int)uVar2) &&
         (iVar6 = *(int *)(param_1 + 0x51c) - *(int *)(param_1 + 0x518), iVar4 = iVar6 * -0x1f8fc7e3
         , uVar2 < (uint)(iVar6 / 0x124))) {
        iVar4 = uVar2 * 0x49;
        *(undefined4 *)(*(int *)(param_1 + 0x518) + 0x48 + uVar2 * 0x124) = uVar3;
      }
    }
  }
  return iVar4;
}


