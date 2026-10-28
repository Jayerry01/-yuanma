void FUN_00501780(char *param_1,undefined4 *param_2,undefined4 param_3,char param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined1 local_40 [64];
  
  FUN_00501e70();
  if (param_4 == '\0') {
    FUN_00501f00(*param_2,param_2[1],param_2[2]);
    FUN_00501f30(0x42b40000,0x3f800000,0,0);
  }
  else {
    FUN_00501830(local_40);
    FUN_00477b90(3,param_2);
    FUN_00502000(local_40);
  }
  FUN_00501f70(param_3,param_3,param_3);
  uVar2 = 0xffffffff;
  iVar3 = 0;
  pcVar4 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (0 < (int)(~uVar2 - 1)) {
    do {
      FUN_00504f50((int)param_1[iVar3]);
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)(~uVar2 - 1));
  }
  FUN_00501ec0();
  return;
}


