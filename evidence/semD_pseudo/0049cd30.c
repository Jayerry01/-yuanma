undefined1 * FUN_0049cd30(undefined1 *param_1,undefined4 param_2)

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
  puStack_c = &LAB_0059f368;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar3 = (undefined1 *)FUN_0049e490(param_1 + 0x10);
  *puVar3 = *param_1;
  *(undefined4 *)(puVar3 + 8) = 0;
  *(undefined4 *)(puVar3 + 0xc) = 0;
  *(undefined4 *)(puVar3 + 4) = param_2;
  iVar1 = *(int *)(param_1 + 0xc);
  local_8 = 0;
  puVar2 = puVar3;
  while( true ) {
    if (iVar1 != 0) {
      uVar4 = FUN_0049cd30(iVar1,puVar2);
      *(undefined4 *)(puVar2 + 0xc) = uVar4;
    }
    param_1 = *(undefined1 **)(param_1 + 8);
    if (param_1 == (undefined1 *)0x0) break;
    puVar5 = (undefined1 *)FUN_0049e490(param_1 + 0x10);
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



void Catch_0049cdc8(void)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  LONG LVar4;
  uint uVar5;
  int iVar6;
  int unaff_EBP;
  uint uVar7;
  int iVar8;
  
  piVar3 = *(int **)(unaff_EBP + 8);
  do {
    piVar1 = piVar3;
    if (piVar1 == (int *)0x0) {
                    // WARNING: Subroutine does not return
      __CxxThrowException_8(0,0);
    }
    FUN_0049cf70(piVar1[3]);
    piVar3 = piVar1 + 5;
    *(int *)(unaff_EBP + -0x18) = piVar1[2];
    *(int **)(unaff_EBP + 8) = piVar3;
    iVar6 = piVar1[6];
    iVar8 = *piVar3;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_004d4a40(iVar8,iVar6);
    iVar6 = *piVar3;
    iVar8 = piVar1[7];
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0049cf50(iVar6,iVar8 - iVar6 >> 2);
    LVar4 = InterlockedExchange(&DAT_005d59e8,1);
    uVar5 = DAT_005d59ec;
    uVar2 = DAT_005c4248;
    if (LVar4 != 0) {
      uVar7 = 0;
      *(undefined4 *)(unaff_EBP + 8) = 0x11;
      if (uVar2 != 0) {
        uVar5 = uVar5 >> 1;
        *(uint *)(unaff_EBP + 0xc) = uVar5;
        do {
          if ((uVar7 < uVar5) || (DAT_005d59e8 != 0)) {
            *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) * *(int *)(unaff_EBP + 8);
            *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) * *(int *)(unaff_EBP + 8);
            *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) * *(int *)(unaff_EBP + 8);
            *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) * *(int *)(unaff_EBP + 8);
          }
          else {
            LVar4 = InterlockedExchange(&DAT_005d59e8,1);
            if (LVar4 == 0) {
              DAT_005c4248 = 1000;
              DAT_005d59ec = uVar7;
              goto LAB_0049ceec;
            }
            uVar5 = *(uint *)(unaff_EBP + 0xc);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar2);
      }
      DAT_005c4248 = 0x1e;
      iVar6 = 6;
      while( true ) {
        iVar8 = iVar6;
        if (0x1b < iVar6) {
          iVar8 = 0x1b;
        }
        LVar4 = InterlockedExchange(&DAT_005d59e8,1);
        if (LVar4 == 0) break;
        if (iVar8 < 0x15) {
          Sleep(0);
          iVar6 = iVar6 + 1;
        }
        else {
          Sleep(1 << ((char)iVar8 - 0x14U & 0x1f));
          iVar6 = iVar6 + 1;
        }
      }
    }
LAB_0049ceec:
    *piVar1 = (int)DAT_005d59b4;
    DAT_005d59e8 = 0;
    piVar3 = *(int **)(unaff_EBP + -0x18);
    DAT_005d59b4 = piVar1;
  } while( true );
}


