void FUN_004315e0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 local_60 [4];
  undefined1 local_50 [16];
  undefined4 local_40 [16];
  
  puVar5 = param_1;
  puVar4 = local_40;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_00431680(local_40,local_50,&param_1,4);
  iVar6 = (int)local_60 - (int)param_2;
  iVar3 = 4;
  puVar5 = param_2;
  do {
    local_60[0] = 0;
    local_60[1] = 0;
    local_60[2] = 0;
    local_60[3] = 0;
    *(undefined4 *)(iVar6 + (int)puVar5) = 0x3f800000;
    FUN_00431900(local_40,local_50,local_60,4);
    iVar2 = 0;
    puVar4 = puVar5;
    do {
      puVar1 = local_60 + iVar2;
      iVar2 = iVar2 + 1;
      *puVar4 = *puVar1;
      puVar4 = puVar4 + 4;
    } while (iVar2 < 4);
    puVar5 = puVar5 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


