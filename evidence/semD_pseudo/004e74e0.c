void * __thiscall FUN_004e74e0(int *param_1,int param_2)

{
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_005a2f80;
  local_10 = ExceptionList;
  pvVar1 = (void *)((param_2 + 0x29U) * -0x79e79e79);
  uVar2 = (param_2 + 0x29U) / 0x2a;
  ExceptionList = &local_10;
  if ((uint)(param_1[5] - *param_1 >> 2) < uVar2) {
    ExceptionList = &local_10;
    pvVar1 = (void *)FUN_0054cc30(uVar2,1);
  }
  local_8 = 0;
  for (uVar3 = 1; uVar3 <= uVar2; uVar3 = uVar3 + 1) {
    pvVar1 = _malloc(0x1f8);
    if (pvVar1 == (void *)0x0) {
      pvVar1 = (void *)FUN_00403440(0x1f8);
    }
    *(void **)(param_1[5] + uVar3 * -4) = pvVar1;
  }
  ExceptionList = local_10;
  return pvVar1;
}



void Catch_004e7578(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  int iVar3;
  
  if (1 < *(uint *)(unaff_EBP + 8)) {
    iVar1 = *(int *)(unaff_EBP + -0x14);
    iVar2 = 4;
    iVar3 = *(uint *)(unaff_EBP + 8) - 1;
    do {
      FUN_005089fd(*(undefined4 *)(*(int *)(iVar1 + 0x14) - iVar2));
      iVar2 = iVar2 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
                    // WARNING: Subroutine does not return
  __CxxThrowException_8(0,0);
}


