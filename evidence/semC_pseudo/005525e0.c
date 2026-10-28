undefined4 FUN_005525e0(char *param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  char *pcVar8;
  undefined1 local_b0 [7];
  undefined1 local_a9;
  undefined4 local_a8;
  int local_a4 [2];
  int local_9c;
  int local_98 [2];
  int local_90;
  char local_8c [128];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a4c6b;
  local_c = ExceptionList;
  if (param_1 == (char *)0x0) {
    return 0;
  }
  iVar3 = -(int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)(local_8c + iVar3)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &local_c;
  pcVar2 = (char *)FUN_0050a22f(local_8c,&DAT_005d121c);
  if (pcVar2 == (char *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar7 = 0xffffffff;
  pcVar8 = pcVar2;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_00403200(pcVar2,pcVar2 + (~uVar7 - 1));
  pcVar2 = (char *)FUN_0050a22f(0,&DAT_005c793c);
  if (pcVar2 == (char *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar7 = 0xffffffff;
  pcVar8 = pcVar2;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_00403200(pcVar2,pcVar2 + (~uVar7 - 1));
  local_b0[0] = 0x3a;
  if (param_3[1] != *param_3) {
    FUN_005531b0(&local_a9,local_b0);
    iVar3 = FUN_005531d0(*param_3,param_3[1],local_a8,local_a8);
    if (iVar3 != param_3[1]) {
      iVar3 = iVar3 - *param_3;
      if (-1 < iVar3) {
        puVar4 = (undefined4 *)FUN_004fb240(local_98,iVar3 + 1,(param_3[1] - *param_3) - iVar3);
        uVar5 = FUN_0050915b(*puVar4);
        *param_4 = uVar5;
        if ((local_98[0] != 0) && (local_90 - local_98[0] != 0)) {
          FUN_00402e90(local_98[0],local_90 - local_98[0]);
        }
        piVar6 = (int *)FUN_004fb240(local_a4,0,iVar3);
        local_4 = 0;
        if (piVar6 != param_3) {
          FUN_00403200(*piVar6,piVar6[1]);
        }
        local_4 = 0xffffffff;
        if ((local_a4[0] != 0) && (local_9c - local_a4[0] != 0)) {
          FUN_00402e90(local_a4[0],local_9c - local_a4[0]);
        }
        goto LAB_005527b9;
      }
    }
  }
  *param_4 = 0x50;
LAB_005527b9:
  uVar7 = 0xffffffff;
  pcVar2 = &DAT_005c793c;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00403200(&DAT_005c793c,~uVar7 + 0x5c793b);
  pcVar2 = (char *)FUN_0050a22f(0,&DAT_005d5a24);
  if (pcVar2 != (char *)0x0) {
    uVar7 = 0xffffffff;
    pcVar8 = pcVar2;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    FUN_00403490(pcVar2,pcVar2 + (~uVar7 - 1));
  }
  ExceptionList = local_c;
  return 1;
}


