undefined4 FUN_0053e050(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = param_1[5];
  if (((iVar3 == 0xcd) || (iVar3 == 0xce)) && ((char)param_1[0x10] == '\0')) {
    if ((uint)param_1[0x1e] < (uint)param_1[0x18]) {
      *(undefined4 *)(*param_1 + 0x14) = 0x43;
      (**(code **)*param_1)(param_1);
    }
    (**(code **)(param_1[0x60] + 4))(param_1);
    param_1[5] = 0xd2;
  }
  else if (iVar3 == 0xcf) {
    param_1[5] = 0xd2;
  }
  else if (iVar3 != 0xd2) {
    *(undefined4 *)(*param_1 + 0x14) = 0x14;
    *(int *)(*param_1 + 0x18) = param_1[5];
    (**(code **)*param_1)(param_1);
  }
  puVar2 = (undefined4 *)param_1[100];
  cVar1 = *(char *)((int)puVar2 + 0x11);
  while( true ) {
    if (cVar1 != '\0') {
      (**(code **)(param_1[6] + 0x18))(param_1);
      FUN_0053e2c0(param_1);
      return 1;
    }
    iVar3 = (*(code *)*puVar2)(param_1);
    if (iVar3 == 0) break;
    puVar2 = (undefined4 *)param_1[100];
    cVar1 = *(char *)((int)puVar2 + 0x11);
  }
  return 0;
}


