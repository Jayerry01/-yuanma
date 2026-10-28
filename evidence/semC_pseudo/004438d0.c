undefined4 __thiscall FUN_004438d0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4 [4];
  
  if (*(int *)(param_1 + 0x3c) != 0) {
    local_14 = param_1;
    FUN_00429e60(*(int *)(param_1 + 0x3c),&local_c,&local_10,local_4);
    iVar3 = param_2;
    FUN_00429d40(*(undefined4 *)(param_1 + 0x3c),local_c,local_10,param_2);
    piVar4 = (int *)**(int **)(param_1 + 8);
    if (piVar4 != *(int **)(param_1 + 8)) {
      do {
        iVar1 = piVar4[2];
        iVar2 = *(int *)(iVar1 + 0x20);
        local_18 = *(int *)(iVar2 + 8);
        if (local_18 != iVar2) {
          do {
            iVar2 = *(int *)(local_18 + 0x14);
            if ((*(int *)(iVar2 + 0x44) == 0) && (*(int *)(iVar2 + 0x1c) != 0)) {
              FUN_00429e60(*(int *)(iVar2 + 0x1c),&local_1c,&param_2,&local_8);
              FUN_00429d40(*(undefined4 *)(iVar2 + 0x1c),local_1c,param_2,iVar3 + 1);
              FUN_00429e60(*(undefined4 *)(iVar2 + 0x20),&local_1c,&param_2,&local_8);
              FUN_00429d40(*(undefined4 *)(iVar2 + 0x20),local_1c,param_2,iVar3 + 2);
            }
            FUN_0043c6c0();
          } while (local_18 != *(int *)(iVar1 + 0x20));
        }
        piVar4 = (int *)*piVar4;
        param_1 = local_14;
      } while (piVar4 != (int *)*(int *)(local_14 + 8));
    }
    iVar1 = *(int *)(param_1 + 0x38);
    if (iVar1 != 0) {
      FUN_00429e60(*(undefined4 *)(iVar1 + 0x54),&local_8,&param_2,&local_14);
      FUN_00429d40(*(undefined4 *)(iVar1 + 0x54),local_8,param_2,iVar3 + 1);
    }
  }
  return 1;
}


