undefined4 __thiscall FUN_0054f310(int param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  DWORD DVar5;
  int *piVar6;
  int local_14;
  short local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a4998;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00553830();
  piVar6 = param_3;
  iVar2 = FUN_00553860(param_3);
  iVar2 = iVar2 + 0x578;
  uVar3 = FUN_00553880(iVar2);
  iVar2 = FUN_00554820(uVar3,iVar2,piVar6);
  if (iVar2 == 0) {
    ExceptionList = local_c;
    return 0;
  }
  if ((iVar2 < 0) || (iVar4 = FUN_00553870(), iVar2 != iVar4)) {
    iVar4 = *(int *)(param_1 + 4);
    iVar2 = *(int *)(iVar4 + 8);
    while (iVar2 != iVar4) {
      piVar6 = *(int **)(iVar2 + 0x14);
      if ((((char)piVar6[0x27] == '\0') && (*piVar6 == *param_3)) &&
         ((short)piVar6[1] == (short)param_3[1])) {
        *(undefined1 *)(piVar6 + 0x27) = 1;
        piVar6[0x28] = 0;
        break;
      }
      FUN_0043c6c0();
      iVar4 = *(int *)(param_1 + 4);
    }
LAB_0054f4c3:
    uVar3 = 0xffffffff;
  }
  else {
    FUN_0054fe60(&local_14);
    local_4 = 0;
    *param_4 = -1;
    iVar2 = *(int *)(*(int *)(param_1 + 4) + 8);
    if (iVar2 != *(int *)(param_1 + 4)) {
      do {
        piVar6 = *(int **)(iVar2 + 0x14);
        if ((((char)piVar6[0x27] == '\0') && (*piVar6 == *param_3)) &&
           ((piVar6[2] == local_14 && ((short)piVar6[3] == local_10)))) {
          *param_4 = piVar6[4];
          DVar5 = timeGetTime();
          piVar6[6] = DVar5;
          *piVar6 = *param_3;
          piVar6[1] = param_3[1];
          break;
        }
        FUN_0043c6c0();
      } while (iVar2 != *(int *)(param_1 + 4));
      if (*param_4 != -1) {
        if ((*(byte *)(param_2 + 5) & 0x10) != 0) {
          uVar3 = FUN_00554670();
          cVar1 = FUN_00553a80(uVar3);
          if (cVar1 == '\0') goto LAB_0054f4c3;
        }
        if ((((*(byte *)(param_2 + 5) & 8) != 0) && (cVar1 = FUN_005539d0(), cVar1 == '\0')) ||
           ((((*(byte *)(param_2 + 5) & 0x40) != 0 && (cVar1 = FUN_00553b20(), cVar1 == '\0')) ||
            ((0x578 < *(ushort *)(param_2 + 0xc) || (cVar1 = FUN_005540e0(param_2), cVar1 == '\0')))
            ))) goto LAB_0054f4c3;
      }
    }
    uVar3 = 1;
  }
  ExceptionList = local_c;
  return uVar3;
}


