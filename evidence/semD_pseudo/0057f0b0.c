FUN_0057f0b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,int param_6)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  if (*(char *)(param_6 + 0x124) == '\0') {
    iVar3 = param_1 + 0x158;
  }
  else {
    iVar3 = *(int *)(param_1 + 4) * 0x40 + *(int *)(param_6 + 0x158);
  }
  puVar2 = (undefined4 *)FUN_00476f00(local_40,iVar3,param_6 + 0x54);
  puVar4 = local_80;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  cVar1 = FUN_00570510(param_1 + 0x198,local_80,param_2,param_3,param_4);
  if (cVar1 != '\0') {
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
      param_5[1] = 0;
      param_5[2] = 0x3f800000;
    }
    return 1;
  }
  return 0;
}


