void FUN_0058b7a0(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  **(undefined1 **)(param_1 + 4) = 0;
  *(undefined1 *)(*(int *)(param_1 + 4) + 1) = 0;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x1c) = 1;
  *(undefined4 *)(param_1 + 0x24) = 0;
  if (param_1 == DAT_0072c0f0) {
    FUN_0058b6c0();
    return;
  }
  return;
}



byte * thunk_FUN_005099a7(byte *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  undefined4 uStack_3c;
  uint uStack_38;
  byte *pbStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  byte *pbStack_28;
  uint uStack_24;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &DAT_005ac490;
  puStack_10 = &LAB_0050a518;
  pvStack_14 = ExceptionList;
  pbVar3 = (byte *)0x0;
  if (param_1 == (byte *)0x0) {
    ExceptionList = &pvStack_14;
    pbVar3 = _malloc(param_2);
  }
  else {
    if (param_2 == 0) {
      ExceptionList = &pvStack_14;
      FUN_005089fd(param_1);
    }
    else {
      ExceptionList = &pvStack_14;
      if (DAT_007f1d70 == 3) {
        do {
          pbStack_28 = (byte *)0x0;
          if (param_2 < 0xffffffe1) {
            FUN_0050dd18(9);
            uStack_8 = 0;
            iStack_2c = FUN_0050cb23(param_1);
            if (iStack_2c != 0) {
              if (param_2 <= DAT_007f1d68) {
                iVar1 = FUN_0050d32c(iStack_2c,param_1,param_2);
                if (iVar1 == 0) {
                  pbStack_28 = (byte *)FUN_0050ce77(param_2);
                  if (pbStack_28 != (byte *)0x0) {
                    uStack_24 = *(int *)(param_1 + -4) - 1;
                    uVar2 = uStack_24;
                    if (param_2 <= uStack_24) {
                      uVar2 = param_2;
                    }
                    FUN_0050c1e0(pbStack_28,param_1,uVar2);
                    iStack_2c = FUN_0050cb23(param_1);
                    FUN_0050cb4e(iStack_2c,param_1);
                  }
                }
                else {
                  pbStack_28 = param_1;
                }
              }
              if (pbStack_28 == (byte *)0x0) {
                if (param_2 == 0) {
                  param_2 = 1;
                }
                param_2 = param_2 + 0xf & 0xfffffff0;
                pbStack_28 = HeapAlloc(DAT_007f1d6c,0,param_2);
                if (pbStack_28 != (byte *)0x0) {
                  uStack_24 = *(int *)(param_1 + -4) - 1;
                  uVar2 = uStack_24;
                  if (param_2 <= uStack_24) {
                    uVar2 = param_2;
                  }
                  FUN_0050c1e0(pbStack_28,param_1,uVar2);
                  FUN_0050cb4e(iStack_2c,param_1);
                }
              }
            }
            uStack_8 = 0xffffffff;
            FUN_00509b32();
            if (iStack_2c == 0) {
              if (param_2 == 0) {
                param_2 = 1;
              }
              param_2 = param_2 + 0xf & 0xfffffff0;
              pbStack_28 = HeapReAlloc(DAT_007f1d6c,0,param_1,param_2);
            }
          }
          if (pbStack_28 != (byte *)0x0) {
            ExceptionList = pvStack_14;
            return pbStack_28;
          }
          if (DAT_00667714 == (byte *)0x0) {
            ExceptionList = pvStack_14;
            return (byte *)0x0;
          }
          iVar1 = FUN_0050f884(param_2);
        } while (iVar1 != 0);
      }
      else {
        ExceptionList = &pvStack_14;
        if (DAT_007f1d70 == 2) {
          ExceptionList = &pvStack_14;
          if (param_2 < 0xffffffe1) {
            if (param_2 == 0) {
              param_2 = 0x10;
              ExceptionList = &pvStack_14;
            }
            else {
              param_2 = param_2 + 0xf & 0xfffffff0;
              ExceptionList = &pvStack_14;
            }
          }
          do {
            pbStack_28 = pbVar3;
            if (param_2 < 0xffffffe1) {
              FUN_0050dd18(9);
              uStack_8 = 1;
              pbVar3 = (byte *)FUN_0050d87e(param_1,&uStack_3c,&uStack_30);
              pbStack_34 = pbVar3;
              if (pbVar3 == (byte *)0x0) {
                pbStack_28 = HeapReAlloc(DAT_007f1d6c,0,param_1,param_2);
              }
              else {
                if (param_2 < DAT_005ccbec) {
                  iVar1 = FUN_0050dc46(uStack_3c,uStack_30,pbVar3,param_2 >> 4);
                  if (iVar1 == 0) {
                    pbStack_28 = (byte *)FUN_0050d91a(param_2 >> 4);
                    if (pbStack_28 != (byte *)0x0) {
                      uStack_38 = (uint)*pbVar3 << 4;
                      uVar2 = uStack_38;
                      if (param_2 <= uStack_38) {
                        uVar2 = param_2;
                      }
                      FUN_0050c1e0(pbStack_28,param_1,uVar2);
                      FUN_0050d8d5(uStack_3c,uStack_30,pbVar3);
                    }
                  }
                  else {
                    pbStack_28 = param_1;
                  }
                }
                if ((pbStack_28 == (byte *)0x0) &&
                   (pbStack_28 = HeapAlloc(DAT_007f1d6c,0,param_2), pbStack_28 != (byte *)0x0)) {
                  uStack_38 = (uint)*pbVar3 << 4;
                  uVar2 = uStack_38;
                  if (param_2 <= uStack_38) {
                    uVar2 = param_2;
                  }
                  FUN_0050c1e0(pbStack_28,param_1,uVar2);
                  FUN_0050d8d5(uStack_3c,uStack_30,pbVar3);
                }
              }
              uStack_8 = 0xffffffff;
              FUN_00509c80();
            }
            if (pbStack_28 != pbVar3) {
              ExceptionList = pvStack_14;
              return pbStack_28;
            }
            if (DAT_00667714 == pbVar3) {
              ExceptionList = pvStack_14;
              return pbStack_28;
            }
            iVar1 = FUN_0050f884(param_2);
          } while (iVar1 != 0);
        }
        else {
          do {
            pbVar3 = (byte *)0x0;
            if (param_2 < 0xffffffe1) {
              if (param_2 == 0) {
                param_2 = 1;
              }
              param_2 = param_2 + 0xf & 0xfffffff0;
              pbVar3 = HeapReAlloc(DAT_007f1d6c,0,param_1,param_2);
            }
            if (pbVar3 != (byte *)0x0) {
              ExceptionList = pvStack_14;
              return pbVar3;
            }
            if (DAT_00667714 == (byte *)0x0) {
              ExceptionList = pvStack_14;
              return (byte *)0x0;
            }
            iVar1 = FUN_0050f884(param_2);
          } while (iVar1 != 0);
        }
      }
    }
    pbVar3 = (byte *)0x0;
  }
  ExceptionList = pvStack_14;
  return pbVar3;
}


