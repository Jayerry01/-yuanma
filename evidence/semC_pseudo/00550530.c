bool __thiscall FUN_00550530(int param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  char local_2c [32];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a4a98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_38 = FUN_00509f8f(param_2,&DAT_005ca380);
  if (local_38 != 0) {
    iVar2 = *(int *)(param_1 + 0x66c);
    iVar3 = *(int *)(param_1 + 0x670);
    iVar7 = FUN_004c6050(iVar3,iVar3,iVar2,iVar2,0);
    iVar4 = *(int *)(param_1 + 0x670);
    iVar6 = local_38;
    for (; local_38 = iVar6, iVar7 != iVar4; iVar7 = iVar7 + 8) {
      FUN_0054e090(0);
      iVar6 = local_38;
    }
    *(int *)(param_1 + 0x670) = *(int *)(param_1 + 0x670) + (iVar3 - iVar2 >> 3) * -8;
    bVar1 = *(byte *)(iVar6 + 0xc);
    while ((bVar1 & 0x10) == 0) {
      FUN_0050b600(iVar6,s__s__d_005ca378,local_2c,&local_38);
      iVar2 = local_38;
      if (((local_2c[0] != '#') && (local_2c[0] != ';')) && (0 < local_38)) {
        FUN_004736b0(local_2c);
        local_30 = CONCAT22(local_30._2_2_,(short)iVar2);
        puVar5 = *(undefined4 **)(param_1 + 0x670);
        local_4 = 0;
        if (puVar5 == *(undefined4 **)(param_1 + 0x674)) {
          FUN_00551530(puVar5,&local_34);
        }
        else {
          if (puVar5 != (undefined4 *)0x0) {
            *puVar5 = local_34;
            puVar5[1] = local_30;
          }
          *(int *)(param_1 + 0x670) = *(int *)(param_1 + 0x670) + 8;
        }
        local_4 = 0xffffffff;
      }
      bVar1 = *(byte *)(iVar6 + 0xc);
    }
    FUN_00509e57(iVar6);
    ExceptionList = local_c;
    return *(int *)(param_1 + 0x670) - *(int *)(param_1 + 0x66c) >> 3 != 0;
  }
  ExceptionList = local_c;
  return false;
}


