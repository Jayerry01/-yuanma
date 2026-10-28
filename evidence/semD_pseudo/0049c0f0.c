undefined1 * FUN_0049c0f0(undefined1 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0059f2f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar3 = (undefined1 *)FUN_0049e160(param_1 + 0x10);
  *puVar3 = *param_1;
  *(undefined4 *)(puVar3 + 8) = 0;
  *(undefined4 *)(puVar3 + 0xc) = 0;
  *(undefined4 *)(puVar3 + 4) = param_2;
  iVar1 = *(int *)(param_1 + 0xc);
  local_8 = 0;
  puVar2 = puVar3;
  while( true ) {
    if (iVar1 != 0) {
      uVar4 = FUN_0049c0f0(iVar1,puVar2);
      *(undefined4 *)(puVar2 + 0xc) = uVar4;
    }
    param_1 = *(undefined1 **)(param_1 + 8);
    if (param_1 == (undefined1 *)0x0) break;
    puVar5 = (undefined1 *)FUN_0049e160(param_1 + 0x10);
    *puVar5 = *param_1;
    *(undefined4 *)(puVar5 + 8) = 0;
    *(undefined4 *)(puVar5 + 0xc) = 0;
    *(undefined1 **)(puVar2 + 8) = puVar5;
    *(undefined1 **)(puVar5 + 4) = puVar2;
    iVar1 = *(int *)(param_1 + 0xc);
    puVar2 = puVar5;
  }
  ExceptionList = local_10;
  return puVar3;
}



void Catch_0049c188(void)

{
  uint uVar1;
  uint uVar2;
  LONG LVar3;
  undefined4 *puVar4;
  int unaff_EBP;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  puVar4 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + 0xc) = puVar4;
  if (puVar4 == (undefined4 *)0x0) {
LAB_0049c2c4:
                    // WARNING: Subroutine does not return
    __CxxThrowException_8(0,0);
  }
  do {
    FUN_0049c2f0(puVar4[3]);
    *(undefined4 *)(unaff_EBP + -0x18) = puVar4[2];
    LVar3 = InterlockedExchange(&DAT_005d59e8,1);
    uVar2 = DAT_005d59ec;
    uVar1 = DAT_005c4248;
    if (LVar3 != 0) {
      uVar5 = 0;
      *(undefined4 *)(unaff_EBP + 8) = 0x11;
      if (uVar1 != 0) {
        do {
          if ((uVar5 < uVar2 >> 1) || (DAT_005d59e8 != 0)) {
            *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) * *(int *)(unaff_EBP + 8);
            *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) * *(int *)(unaff_EBP + 8);
            *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) * *(int *)(unaff_EBP + 8);
            *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) * *(int *)(unaff_EBP + 8);
          }
          else {
            LVar3 = InterlockedExchange(&DAT_005d59e8,1);
            if (LVar3 == 0) {
              puVar4 = *(undefined4 **)(unaff_EBP + 0xc);
              DAT_005c4248 = 1000;
              DAT_005d59ec = uVar5;
              goto LAB_0049c29e;
            }
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar1);
        puVar4 = *(undefined4 **)(unaff_EBP + 0xc);
      }
      DAT_005c4248 = 0x1e;
      iVar7 = 6;
      while( true ) {
        iVar6 = iVar7;
        if (0x1b < iVar7) {
          iVar6 = 0x1b;
        }
        LVar3 = InterlockedExchange(&DAT_005d59e8,1);
        if (LVar3 == 0) break;
        if (iVar6 < 0x15) {
          Sleep(0);
          iVar7 = iVar7 + 1;
        }
        else {
          Sleep(1 << ((char)iVar6 - 0x14U & 0x1f));
          iVar7 = iVar7 + 1;
        }
      }
    }
LAB_0049c29e:
    iVar7 = *(int *)(unaff_EBP + -0x18);
    *puVar4 = DAT_005d59b0;
    DAT_005d59e8 = 0;
    DAT_005d59b0 = puVar4;
    *(int *)(unaff_EBP + 0xc) = iVar7;
    if (iVar7 == 0) goto LAB_0049c2c4;
    puVar4 = *(undefined4 **)(unaff_EBP + 0xc);
  } while( true );
}


