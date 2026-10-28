void __thiscall FUN_004aabb0(int *param_1,uint *param_2)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  
  uVar6 = (param_1[1] - *param_1) + 0xc;
  pcVar2 = operator_new(uVar6);
  pcVar4 = (char *)*param_1;
  pcVar7 = pcVar2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar7 = cVar1;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  piVar3 = (int *)(pcVar2 + (param_1[1] - *param_1));
  *piVar3 = param_1[9];
  piVar3[1] = param_1[10];
  uVar5 = (uint)(param_1[0xf] != 0);
  if (param_1[0x15] != 0) {
    uVar5 = uVar5 | 2;
  }
  if (param_1[0x11] != 0) {
    uVar5 = uVar5 | 4;
  }
  if (param_1[0x12] != 0) {
    uVar5 = uVar5 | 8;
  }
  if (param_1[0x10] != 0) {
    uVar5 = uVar5 | 0x10;
  }
  if (param_1[0x13] != 0) {
    uVar5 = uVar5 | 0x20;
  }
  piVar3[2] = uVar5;
  *param_2 = uVar6;
  return;
}


