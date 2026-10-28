void __thiscall FUN_004ab3f0(char *param_1,int *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  int local_108;
  int local_104;
  char local_100 [256];
  
  cVar1 = *param_1;
  if (param_2[1] + 1 == param_2[2]) {
    local_104 = 1;
    local_108 = param_2[1] - *param_2;
    piVar4 = &local_104;
    if (local_108 != 0) {
      piVar4 = &local_108;
    }
    FUN_0049be40(*piVar4 + local_108);
  }
  FUN_00402bc0(param_2[1] + 1);
  *(char *)param_2[1] = cVar1 + '\x01';
  iVar3 = param_2[1];
  iVar6 = iVar3 + 1;
  param_2[1] = iVar6;
  cVar1 = param_1[1];
  if (iVar3 + 2 == param_2[2]) {
    local_104 = iVar6 - *param_2;
    local_108 = 1;
    piVar4 = (int *)FUN_0049c0d0(&local_104,&local_108);
    FUN_0049be40((param_2[1] - *param_2) + *piVar4);
  }
  FUN_00402bc0(param_2[1] + 1);
  *(char *)param_2[1] = cVar1 + '\x01';
  iVar3 = param_2[1];
  iVar6 = iVar3 + 1;
  param_2[1] = iVar6;
  cVar1 = param_1[2];
  if (iVar3 + 2 == param_2[2]) {
    local_108 = 1;
    local_104 = iVar6 - *param_2;
    piVar4 = (int *)FUN_0049c0d0(&local_104,&local_108);
    FUN_0049be40((param_2[1] - *param_2) + *piVar4);
  }
  FUN_00402bc0(param_2[1] + 1);
  *(char *)param_2[1] = cVar1 + '\x01';
  iVar3 = param_2[1];
  iVar6 = iVar3 + 1;
  param_2[1] = iVar6;
  cVar1 = param_1[8];
  cVar2 = param_1[4];
  if (iVar3 + 2 == param_2[2]) {
    local_104 = iVar6 - *param_2;
    local_108 = 1;
    piVar4 = (int *)FUN_0049c0d0(&local_104,&local_108);
    FUN_0049be40((*piVar4 - *param_2) + param_2[1]);
  }
  FUN_00402bc0(param_2[1] + 1);
  *(char *)param_2[1] = (cVar1 - cVar2) + '\x01';
  param_2[1] = param_2[1] + 1;
  FUN_004b4050(param_1 + 4);
  cVar1 = param_1[0x14];
  cVar2 = param_1[0x10];
  if (param_2[1] + 1 == param_2[2]) {
    local_104 = param_2[1] - *param_2;
    local_108 = 1;
    piVar4 = (int *)FUN_0049c0d0(&local_104,&local_108);
    FUN_0049be40((param_2[1] - *param_2) + *piVar4);
  }
  FUN_00402bc0(param_2[1] + 1);
  *(char *)param_2[1] = (cVar1 - cVar2) + '\x01';
  param_2[1] = param_2[1] + 1;
  FUN_004b4050(param_1 + 0x10);
  cVar1 = param_1[0x20];
  cVar2 = param_1[0x1c];
  if (param_2[1] + 1 == param_2[2]) {
    local_104 = param_2[1] - *param_2;
    local_108 = 1;
    piVar4 = (int *)FUN_0049c0d0(&local_104,&local_108);
    FUN_0049be40((param_2[1] - *param_2) + *piVar4);
  }
  FUN_00402bc0(param_2[1] + 1);
  *(char *)param_2[1] = (cVar1 - cVar2) + '\x01';
  param_2[1] = param_2[1] + 1;
  FUN_004b4050(param_1 + 0x1c);
  cVar1 = param_1[0x2c];
  cVar2 = param_1[0x28];
  if (param_2[1] + 1 == param_2[2]) {
    local_104 = param_2[1] - *param_2;
    local_108 = 1;
    piVar4 = (int *)FUN_0049c0d0(&local_104,&local_108);
    FUN_0049be40((param_2[1] - *param_2) + *piVar4);
  }
  FUN_00402bc0(param_2[1] + 1);
  *(char *)param_2[1] = (cVar1 - cVar2) + '\x01';
  param_2[1] = param_2[1] + 1;
  FUN_004b4050(param_1 + 0x28);
  cVar1 = param_1[0x38];
  cVar2 = param_1[0x34];
  if (param_2[1] + 1 == param_2[2]) {
    local_104 = param_2[1] - *param_2;
    local_108 = 1;
    piVar4 = (int *)FUN_0049c0d0(&local_104,&local_108);
    FUN_0049be40((*piVar4 - *param_2) + param_2[1]);
  }
  FUN_00402bc0(param_2[1] + 1);
  *(char *)param_2[1] = (cVar1 - cVar2) + '\x01';
  param_2[1] = param_2[1] + 1;
  FUN_004b4050(param_1 + 0x34);
  FUN_0050aaa9(*(undefined4 *)(param_1 + 0x44),local_100,10);
  uVar5 = 0xffffffff;
  pcVar7 = local_100;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_00498c40(CONCAT31((int3)(~uVar5 - 1 >> 8),(char)(~uVar5 - 1) + '\x01'));
  FUN_004b4070(local_100);
  return;
}


