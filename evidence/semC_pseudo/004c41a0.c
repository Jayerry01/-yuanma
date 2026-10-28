void __thiscall FUN_004c41a0(int *param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a13ab;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar4 = FUN_004fb440();
  iVar5 = param_1[1];
  iVar2 = *param_1;
  local_4 = 0;
  if (param_2 < (uint)((iVar5 - iVar2) / 0x124)) {
    puVar3 = (undefined4 *)param_1[1];
    puVar1 = (undefined4 *)(iVar2 + param_2 * 0x124);
    for (puVar6 = puVar1; puVar6 != puVar3; puVar6 = puVar6 + 0x49) {
      (**(code **)*puVar6)(0);
    }
    iVar5 = iVar5 - (int)puVar1;
    iVar5 = (int)((ulonglong)((longlong)iVar5 * 0x1f8fc7e3) >> 0x20) - iVar5;
    param_1[1] = param_1[1] + ((iVar5 >> 8) - (iVar5 >> 0x1f)) * 0x124;
  }
  else {
    FUN_004c5200(iVar5,param_2 - (iVar5 - iVar2) / 0x124,uVar4);
  }
  local_4 = 0xffffffff;
  FUN_004fb550();
  ExceptionList = pvStack_c;
  return;
}


