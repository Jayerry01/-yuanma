bool __thiscall FUN_004a34a0(int *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  HANDLE pvVar5;
  char *pcVar6;
  char *pcVar7;
  _WIN32_FIND_DATAA *p_Var8;
  undefined4 unaff_retaddr;
  undefined4 uStack_574;
  undefined4 uStack_570;
  undefined4 uStack_56c;
  undefined4 uStack_568;
  undefined4 uStack_564;
  undefined4 uStack_560;
  undefined4 uStack_55c;
  undefined4 uStack_558;
  undefined4 uStack_554;
  undefined4 uStack_550;
  undefined4 uStack_54c;
  undefined4 uStack_548;
  char acStack_544 [256];
  undefined1 auStack_444 [256];
  undefined1 auStack_344 [256];
  CHAR aCStack_244 [256];
  _WIN32_FIND_DATAA _Stack_144;
  
  if (param_3 == 0) {
    iVar3 = (**(code **)(param_1[0xc] + 0xc))(s_mface_005c96cc);
  }
  else {
    iVar3 = (**(code **)(param_1[0xc] + 0xc))(param_3);
  }
  if (iVar3 == 0) {
    uStack_574 = 0x3f333333;
    uStack_570 = 0x3f333333;
    uStack_56c = 0x3f333333;
    uStack_568 = 0x3f333333;
    uStack_564 = 0x3f333333;
    uStack_560 = 0x3f333333;
    uStack_55c = 0x3f333333;
    uStack_558 = 0x3f333333;
    uStack_554 = 0x3f333333;
    uStack_550 = 0;
    uStack_54c = 0;
    uStack_548 = 0;
  }
  else {
    uVar4 = FUN_0040ed10(iVar3,0);
    FUN_0040f550(uVar4,&uStack_574,&uStack_568,&uStack_55c,&uStack_550,acStack_544);
  }
  (**(code **)(*param_1 + 0x38))();
  FUN_004a8160(unaff_retaddr,acStack_544,0);
  iVar3 = -1;
  pcVar6 = acStack_544;
  do {
    pcVar7 = pcVar6;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar7 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar7;
  } while (cVar1 != '\0');
  *(undefined2 *)(pcVar7 + -1) = _DAT_005c6838;
  while( true ) {
    FUN_0042a910(auStack_344);
    FUN_00508ae6(auStack_444,s__s_02d_005c44b0,acStack_544,param_1[0x68] - param_1[0x67] >> 2);
    FUN_00508ae6(aCStack_244,s__s_s___005c96c4,auStack_344,auStack_444);
    p_Var8 = &_Stack_144;
    for (iVar3 = 0x50; iVar3 != 0; iVar3 = iVar3 + -1) {
      p_Var8->dwFileAttributes = 0;
      p_Var8 = (_WIN32_FIND_DATAA *)&p_Var8->ftCreationTime;
    }
    pvVar5 = FindFirstFileA(aCStack_244,&_Stack_144);
    if (pvVar5 == (HANDLE)0xffffffff) break;
    uVar4 = FUN_0040ed80(&uStack_574,&uStack_568,&uStack_55c,&uStack_550,0x42200000,auStack_444,0,0,
                         0,0,0);
    puVar2 = (undefined4 *)param_1[0x68];
    if (puVar2 == (undefined4 *)param_1[0x69]) {
      FUN_0049c640(puVar2,&stack0xfffffa88);
    }
    else {
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = uVar4;
      }
      param_1[0x68] = param_1[0x68] + 4;
    }
  }
  return param_1[0x68] - param_1[0x67] >> 2 != 0;
}


