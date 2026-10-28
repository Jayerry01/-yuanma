undefined4 __thiscall FUN_005567d0(int param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  undefined1 local_20 [32];
  
  FUN_0050b600(param_2,s__s__s_005d12a8,local_20,param_3);
  FUN_00571c70(param_2,1);
  FUN_0050b600(param_2,s__s__s_005d12a8,local_20,param_3 + 0x10);
  cVar1 = param_3[0x10];
  if (cVar1 == 'b') {
    param_3[0xa0] = '\x02';
    param_3[0xa1] = '\0';
    param_3[0xa2] = '\0';
    param_3[0xa3] = '\0';
  }
  else {
    if (cVar1 != 'd') {
      param_3[0xa0] = '\x01';
      param_3[0xa1] = '\0';
      param_3[0xa2] = '\0';
      param_3[0xa3] = '\0';
      goto LAB_00556856;
    }
    param_3[0xa0] = '\x03';
    param_3[0xa1] = '\0';
    param_3[0xa2] = '\0';
    param_3[0xa3] = '\0';
  }
  uVar2 = FUN_0050915b(param_3 + 0x11);
  *(undefined4 *)(param_3 + 0xa4) = uVar2;
LAB_00556856:
  *(undefined4 *)(param_3 + 0x24) = *(undefined4 *)(param_3 + 0xa0);
  *(undefined4 *)(param_3 + 0x28) = *(undefined4 *)(param_3 + 0xa4);
  FUN_0050b600(param_2,s__s__f__f__f_005d1298,local_20,param_3 + 0x30,param_3 + 0x34,param_3 + 0x38)
  ;
  *(undefined4 *)(param_3 + 0x94) = *(undefined4 *)(param_3 + 0x30);
  *(undefined4 *)(param_3 + 0x98) = *(undefined4 *)(param_3 + 0x34);
  *(undefined4 *)(param_3 + 0x9c) = *(undefined4 *)(param_3 + 0x38);
  FUN_0050b600(param_2,s__s__f__f__f__f_005d1288,local_20,param_3 + 0x84,param_3 + 0x88,
               param_3 + 0x8c,param_3 + 0x90);
  FUN_00571c70(param_2,1);
  iVar3 = 7;
  bVar6 = true;
  pcVar4 = param_3;
  pcVar5 = s_d_base_005c928c;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    uVar2 = *(undefined4 *)(param_3 + 0x2c);
    *(char **)(param_1 + 900) = param_3;
    *(undefined4 *)(param_1 + 0x24) = uVar2;
  }
  return 1;
}


