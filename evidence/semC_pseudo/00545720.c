int FUN_00545720(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  int *piVar6;
  int local_4;
  
  if (param_3 < param_4) {
    local_4 = param_3 * 2;
    piVar6 = (int *)(param_3 * 0x20 + 0xc + param_2);
    do {
      if (param_4 < local_4) {
        piVar2 = (int *)FUN_005458a0(param_2,param_3);
      }
      else {
        piVar2 = (int *)FUN_00545860();
      }
      if (piVar2 == (int *)0x0) {
        return param_3;
      }
      piVar1 = piVar6 + -3;
      piVar6[-2] = piVar2[1];
      *piVar6 = piVar2[3];
      piVar6[2] = piVar2[5];
      *piVar1 = *piVar2;
      piVar6[-1] = piVar2[2];
      piVar6[1] = piVar2[4];
      iVar3 = (piVar2[1] - *piVar2) * 0x10;
      iVar4 = (piVar2[3] - piVar2[2]) * 0xc;
      cVar5 = iVar3 <= iVar4;
      if (!(bool)cVar5) {
        iVar4 = iVar3;
      }
      if (iVar4 < (piVar2[5] - piVar2[4]) * 8) {
        cVar5 = '\x02';
      }
      if (cVar5 == '\0') {
        iVar4 = (piVar2[1] + *piVar2) / 2;
        piVar2[1] = iVar4;
        *piVar1 = iVar4 + 1;
      }
      else if (cVar5 == '\x01') {
        iVar4 = (piVar2[3] + piVar2[2]) / 2;
        piVar2[3] = iVar4;
        piVar6[-1] = iVar4 + 1;
      }
      else if (cVar5 == '\x02') {
        iVar4 = (piVar2[5] + piVar2[4]) / 2;
        piVar2[5] = iVar4;
        piVar6[1] = iVar4 + 1;
      }
      FUN_00545360(param_1,piVar2);
      FUN_00545360(param_1,piVar1);
      param_3 = param_3 + 1;
      local_4 = local_4 + 2;
      piVar6 = piVar6 + 8;
    } while (param_3 < param_4);
  }
  return param_3;
}


