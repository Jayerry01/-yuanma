void FUN_00434690(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,undefined4 param_8)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int local_2c;
  undefined1 local_28 [40];
  
  if (param_3 < 2) {
    local_2c = 1;
  }
  else {
    local_2c = param_3;
  }
  if ((param_1 != (int *)0x0) || (param_1 = DAT_005d9b78, DAT_005d9b78 != (int *)0x0)) {
    if (*param_1 != 0) {
      iVar3 = 0;
      if (0 < param_1[9]) {
        do {
          FUN_00433ea0(*(undefined4 *)(*param_1 + iVar3 * 4));
          iVar3 = iVar3 + 1;
        } while (iVar3 < param_1[9]);
      }
      FUN_005089fd(*param_1);
    }
    pvVar1 = _malloc(local_2c * 4);
    *param_1 = (int)pvVar1;
    if (param_2 == 0) {
      iVar3 = 0;
      if (0 < local_2c) {
        do {
          uVar2 = FUN_00434310(param_5 * param_6,param_4 * param_7);
          *(undefined4 *)(*param_1 + iVar3 * 4) = uVar2;
          iVar3 = iVar3 + 1;
        } while (iVar3 < local_2c);
      }
      *(int *)(DAT_005d5b04 + 0x10) = param_6;
      *(int *)(DAT_005d5b04 + 0x14) = param_7;
      param_1[7] = param_4;
      param_1[8] = param_5;
    }
    else {
      if (param_3 == 0) {
        FUN_00433ad0();
        FUN_00433b60(0,param_2,param_8);
        uVar2 = FUN_00433e90();
        *(undefined4 *)*param_1 = uVar2;
      }
      else {
        iVar3 = 0;
        if (0 < local_2c) {
          do {
            FUN_00508ae6(local_28,s__s_02d_005c44b0,param_2,iVar3);
            FUN_00433ad0();
            FUN_00433b60(0,local_28,param_8);
            uVar2 = FUN_00433e90();
            iVar3 = iVar3 + 1;
            *(undefined4 *)(*param_1 + -4 + iVar3 * 4) = uVar2;
          } while (iVar3 < local_2c);
        }
      }
      if ((param_6 < 1) || (param_7 < 1)) {
        param_1[7] = 1;
        param_1[8] = 1;
        *(undefined4 *)(DAT_005d5b04 + 0x10) = *(undefined4 *)(*(int *)*param_1 + 8);
        param_6 = *(int *)(DAT_005d5b04 + 0x10);
        *(undefined4 *)(DAT_005d5b04 + 0x14) = *(undefined4 *)(*(int *)*param_1 + 0xc);
        param_7 = *(int *)(DAT_005d5b04 + 0x14);
      }
      else {
        param_1[8] = *(int *)(*(int *)*param_1 + 8) / param_6;
        param_1[7] = *(int *)(*(int *)*param_1 + 0xc) / param_7;
      }
    }
    param_1[5] = param_6;
    param_1[6] = param_7;
    param_1[9] = local_2c;
    param_1[10] = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    if ((param_1[3] == 0) && (param_1[4] == 0)) {
      SetRect((LPRECT)(param_1 + 1),0,0,param_6,param_7);
      FUN_004345a0(param_1);
      return;
    }
    FUN_004348b0(param_1,param_1 + 1);
  }
  return;
}


