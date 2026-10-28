undefined4 FUN_00541880(undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  
  piVar1 = (int *)param_1[4];
  pbVar5 = (byte *)*param_1;
  iVar6 = param_1[1];
  if (piVar1[0x5f] == 0) {
    for (; param_3 < 0x19; param_3 = param_3 + 8) {
      if (iVar6 == 0) {
        cVar3 = (**(code **)(piVar1[6] + 0xc))(piVar1);
        if (cVar3 == '\0') {
          return 0;
        }
        pbVar5 = *(byte **)piVar1[6];
        iVar6 = ((undefined4 *)piVar1[6])[1];
      }
      iVar6 = iVar6 + -1;
      uVar4 = (uint)*pbVar5;
      pbVar5 = pbVar5 + 1;
      if (uVar4 == 0xff) {
        do {
          if (iVar6 == 0) {
            cVar3 = (**(code **)(piVar1[6] + 0xc))(piVar1);
            if (cVar3 == '\0') {
              return 0;
            }
            pbVar5 = *(byte **)piVar1[6];
            iVar6 = ((undefined4 *)piVar1[6])[1];
          }
          iVar6 = iVar6 + -1;
          uVar4 = (uint)*pbVar5;
          pbVar5 = pbVar5 + 1;
        } while (uVar4 == 0xff);
        if (uVar4 != 0) {
          piVar1[0x5f] = uVar4;
          goto LAB_0054192d;
        }
        uVar4 = 0xff;
      }
      param_2 = param_2 << 8 | uVar4;
    }
  }
  else {
LAB_0054192d:
    iVar2 = param_3;
    if (param_3 < param_4) {
      if (*(char *)(piVar1[0x66] + 8) == '\0') {
        *(undefined4 *)(*piVar1 + 0x14) = 0x75;
        (**(code **)(*piVar1 + 4))(piVar1,0xffffffff);
        *(undefined1 *)(piVar1[0x66] + 8) = 1;
      }
      param_3 = 0x19;
      param_2 = param_2 << (0x19U - (char)iVar2 & 0x1f);
    }
  }
  param_1[1] = iVar6;
  *param_1 = pbVar5;
  param_1[2] = param_2;
  param_1[3] = param_3;
  return 1;
}


