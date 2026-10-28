void FUN_0041a490(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  ushort uVar7;
  undefined4 uVar8;
  
  if (((DAT_005c4618 < 0) || (0x13ff < DAT_005c4618)) || ((&DAT_007e5be0)[DAT_005c4618] == 0)) {
    iVar1 = *(int *)(DAT_005d5a0c + 0x748);
    if (DAT_005c4620 != *(int *)(iVar1 + 4)) {
      *(undefined4 *)(iVar1 + 0x28) = DAT_005c461c;
      *(undefined4 *)(iVar1 + 0x18) = DAT_005c461c;
      *(undefined4 *)(iVar1 + 0x38) = DAT_005c461c;
      *(undefined4 *)(iVar1 + 0x48) = DAT_005c461c;
      *(int *)(*(int *)(DAT_005d5a0c + 0x748) + 4) = DAT_005c4620;
      piVar2 = *(int **)(*(int *)(DAT_005d5a0c + 0x748) + 0x58);
      (**(code **)(*piVar2 + 0xc))(piVar2,iVar1 + 8);
      uVar3 = __ftol();
      uVar7 = CONCAT11((undefined1)DAT_005c4620,uVar3);
      uVar4 = __ftol();
      uVar5 = __ftol();
      **(uint **)(DAT_005d5a0c + 0x748) = ((uint)uVar7 << 8 | uVar4 & 0xff) << 8 | uVar5 & 0xff;
    }
    (**(code **)(*param_1 + 0x98))(param_1,0,0);
    FUN_0041a950(param_1,1,*(undefined4 *)(*(int *)(DAT_005d5a0c + 0x748) + 0x5c));
    _DAT_007e2c80 = *(float *)(iVar1 + 0x3c) * 255.0;
    _DAT_007e2be8 = *(float *)(iVar1 + 0x40) * 255.0;
    _DAT_007e2be4 = *(float *)(iVar1 + 0x44) * 255.0;
    _DAT_007e2804 = *(float *)(iVar1 + 0xc) * 255.0;
    _DAT_007e277c = *(float *)(iVar1 + 0x10) * 255.0;
    _DAT_007e2770 = *(float *)(iVar1 + 0x14) * 255.0;
    _DAT_007e2330 = *(float *)(iVar1 + 0x1c) * 255.0;
    _DAT_007e2320 = *(float *)(iVar1 + 0x20) * 255.0;
    _DAT_007e231c = *(float *)(iVar1 + 0x24) * 255.0;
    DAT_005d5ae0 = **(undefined4 **)(DAT_005d5a0c + 0x748);
    puVar6 = *(undefined4 **)(DAT_005d5a0c + 0x748);
    goto LAB_0041a932;
  }
  iVar1 = *(int *)((&DAT_007e5be0)[DAT_005c4618] + 0x3c);
  if (DAT_005c4620 == *(int *)(iVar1 + 4)) {
    if (((((*(float *)(iVar1 + 0x3c) * 255.0 != _DAT_007e2c80) ||
          (*(float *)(iVar1 + 0x40) * 255.0 != _DAT_007e2be8)) ||
         ((*(float *)(iVar1 + 0x44) * 255.0 != _DAT_007e2be4 ||
          ((*(float *)(iVar1 + 0xc) * 255.0 != _DAT_007e2804 ||
           (*(float *)(iVar1 + 0x10) * 255.0 != _DAT_007e277c)))))) ||
        (*(float *)(iVar1 + 0x14) * 255.0 != _DAT_007e2770)) ||
       ((((*(float *)(iVar1 + 0x1c) * 255.0 != _DAT_007e2330 ||
          (*(float *)(iVar1 + 0x20) * 255.0 != _DAT_007e2320)) ||
         (*(float *)(iVar1 + 0x24) * 255.0 != _DAT_007e231c)) || (DAT_005d5a38 != DAT_005c4620)))) {
      uVar8 = *(undefined4 *)(iVar1 + 0x5c);
      goto LAB_0041a807;
    }
  }
  else {
    *(undefined4 *)(iVar1 + 0x28) = DAT_005c461c;
    *(undefined4 *)(iVar1 + 0x18) = DAT_005c461c;
    *(undefined4 *)(iVar1 + 0x38) = DAT_005c461c;
    *(undefined4 *)(iVar1 + 0x48) = DAT_005c461c;
    *(int *)(*(int *)((&DAT_007e5be0)[DAT_005c4618] + 0x3c) + 4) = DAT_005c4620;
    piVar2 = *(int **)(*(int *)((&DAT_007e5be0)[DAT_005c4618] + 0x3c) + 0x58);
    (**(code **)(*piVar2 + 0xc))(piVar2,iVar1 + 8);
    uVar3 = __ftol();
    uVar7 = CONCAT11((undefined1)DAT_005c4620,uVar3);
    uVar4 = __ftol();
    uVar5 = __ftol();
    **(uint **)((&DAT_007e5be0)[DAT_005c4618] + 0x3c) =
         ((uint)uVar7 << 8 | uVar4 & 0xff) << 8 | uVar5 & 0xff;
    uVar8 = *(undefined4 *)(*(int *)((&DAT_007e5be0)[DAT_005c4618] + 0x3c) + 0x5c);
LAB_0041a807:
    FUN_0041a950(param_1,1,uVar8);
    _DAT_007e2c80 = *(float *)(iVar1 + 0x3c) * 255.0;
    _DAT_007e2be8 = *(float *)(iVar1 + 0x40) * 255.0;
    _DAT_007e2be4 = *(float *)(iVar1 + 0x44) * 255.0;
    _DAT_007e2804 = *(float *)(iVar1 + 0xc) * 255.0;
    _DAT_007e277c = *(float *)(iVar1 + 0x10) * 255.0;
    _DAT_007e2770 = *(float *)(iVar1 + 0x14) * 255.0;
    _DAT_007e2330 = *(float *)(iVar1 + 0x1c) * 255.0;
    _DAT_007e2320 = *(float *)(iVar1 + 0x20) * 255.0;
    _DAT_007e231c = *(float *)(iVar1 + 0x24) * 255.0;
  }
  iVar1 = *(int *)((&DAT_007e5be0)[DAT_005c4618] + 0x34);
  if ((iVar1 == 0) || (param_2 == 1)) {
    (**(code **)(*param_1 + 0x98))(param_1,0,0);
  }
  else {
    if (*(int *)(iVar1 + 0x40) == 0) {
      FUN_004157e0(iVar1);
      (**(code **)(*param_1 + 0x98))
                (param_1,0,*(undefined4 *)(*(int *)((&DAT_007e5be0)[DAT_005c4618] + 0x34) + 0x40));
    }
    else {
      (**(code **)(*param_1 + 0x98))(param_1,0,*(int *)(iVar1 + 0x40));
    }
    *(undefined4 *)(*(int *)((&DAT_007e5be0)[DAT_005c4618] + 0x34) + 0x34) = 0;
  }
  DAT_005d5ae0 = **(undefined4 **)((&DAT_007e5be0)[DAT_005c4618] + 0x3c);
  puVar6 = *(undefined4 **)((&DAT_007e5be0)[DAT_005c4618] + 0x3c);
LAB_0041a932:
  DAT_005d5ae4 = *puVar6;
  DAT_005d5a38 = DAT_005c4620;
  return;
}


