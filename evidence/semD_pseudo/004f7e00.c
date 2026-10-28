FUN_004f7e00(undefined2 *param_1,undefined2 param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  undefined2 *local_4;
  
  local_4 = param_1;
  FUN_004f7d30();
  *(undefined4 *)(param_1 + 0x18) = param_3;
  local_4 = operator_new(0x14);
  *local_4 = param_2;
  *(undefined4 *)(local_4 + 2) = 0;
  fVar4 = (float10)FUN_004f81e0(local_4);
  *(float *)(local_4 + 4) = (float)fVar4;
  *(float *)(local_4 + 6) = *(float *)(local_4 + 4) + *(float *)(local_4 + 2);
  *(undefined4 *)(local_4 + 8) = 0;
  puVar1 = *(undefined4 **)(param_1 + 4);
  if (puVar1 == *(undefined4 **)(param_1 + 6)) {
    FUN_004f84b0(puVar1,&local_4);
  }
  else {
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = local_4;
    }
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 4;
  }
  iVar3 = 0;
  while( true ) {
    iVar2 = FUN_004f7ec0();
    if (iVar2 == 0) {
      return 1;
    }
    if (iVar2 == 1) break;
    iVar3 = iVar3 + 1;
    if (param_4 < iVar3) {
      return 1;
    }
  }
  return 0;
}


