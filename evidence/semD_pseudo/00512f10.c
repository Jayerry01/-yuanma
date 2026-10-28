void FUN_00512f10(int param_1,int *param_2,ushort *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_5c [40];
  undefined8 local_34;
  uint local_24;
  
  param_3 = (ushort *)(uint)*param_3;
  iVar1 = *param_2;
  if (iVar1 == 1) {
LAB_00512f55:
    uVar2 = 8;
  }
  else if (iVar1 == 2) {
    uVar2 = 4;
  }
  else if (iVar1 == 3) {
    uVar2 = 0x11;
  }
  else if (iVar1 == 4) {
    uVar2 = 0x12;
  }
  else {
    if (iVar1 == 5) goto LAB_00512f55;
    if (iVar1 == 7) {
      *param_2 = 1;
      goto LAB_00512fab;
    }
    if (iVar1 != 8) goto LAB_00512fab;
    uVar2 = 0x10;
  }
  iVar1 = FUN_0051478a(uVar2,param_2 + 6,param_3);
  if (iVar1 == 0) {
    if (((param_1 == 0x10) || (param_1 == 0x16)) || (param_1 == 0x1d)) {
      local_34 = *(undefined8 *)(param_2 + 4);
      local_24 = local_24 & 0xffffffe3 | 3;
    }
    else {
      local_24 = local_24 & 0xfffffffe;
    }
    FUN_005144d7(local_5c,&param_3,uVar2,param_1,param_2 + 2,param_2 + 6);
  }
LAB_00512fab:
  FUN_00514ac3(param_3,0xffff);
  if (((*param_2 != 8) && (DAT_005cd498 == 0)) && (iVar1 = FUN_00514aa3(param_2), iVar1 != 0)) {
    return;
  }
  FUN_00514a29(*param_2);
  return;
}



undefined4