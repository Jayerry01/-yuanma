int FUN_00538940(int *param_1,char param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == '\0') {
    return ((*(int *)(param_4 + (param_3 + (*param_1 * 0x21 + param_1[2]) * 0x21) * 4) -
            *(int *)(param_4 + (param_3 + (param_1[2] + param_1[1] * 0x21) * 0x21) * 4)) -
           *(int *)(param_4 + (param_3 + (*param_1 * 0x21 + param_1[3]) * 0x21) * 4)) +
           *(int *)(param_4 + (param_3 + (param_1[1] * 0x21 + param_1[3]) * 0x21) * 4);
  }
  if (param_2 != '\x01') {
    if (param_2 != '\x02') {
      return 0;
    }
    iVar1 = (param_1[3] + param_3 * 0x21) * 0x21;
    iVar2 = (param_1[2] + param_3 * 0x21) * 0x21;
    return ((*(int *)(param_4 + (param_1[4] + iVar2) * 4) -
            *(int *)(param_4 + (param_1[4] + iVar1) * 4)) -
           *(int *)(param_4 + (iVar2 + param_1[5]) * 4)) +
           *(int *)(param_4 + (param_1[5] + iVar1) * 4);
  }
  iVar1 = (param_3 + param_1[1] * 0x21) * 0x21;
  iVar2 = (param_3 + *param_1 * 0x21) * 0x21;
  return ((*(int *)(param_4 + (iVar2 + param_1[4]) * 4) -
          *(int *)(param_4 + (param_1[4] + iVar1) * 4)) -
         *(int *)(param_4 + (iVar2 + param_1[5]) * 4)) +
         *(int *)(param_4 + (iVar1 + param_1[5]) * 4);
}


