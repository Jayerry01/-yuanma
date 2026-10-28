undefined4 __thiscall FUN_00462050(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iStack_4;
  
  iVar1 = param_2;
  piVar3 = (int *)**(int **)(param_1 + 0x14);
  iStack_4 = param_1;
  if (piVar3 != *(int **)(param_1 + 0x14)) {
    do {
      iVar2 = FUN_004621a0();
      if (iVar2 == 0) {
        (**(code **)(*(int *)piVar3[2] + 0xc))(iVar1);
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)*(int *)(param_1 + 0x14));
  }
  iVar2 = FUN_00463450();
  if (iVar2 != 0) {
    FUN_0044ee60(iVar1);
  }
  FUN_0044ef10();
  FUN_00473230(iVar1);
  FUN_00410400(&iStack_4,&param_2);
  FUN_00429d00(*(undefined4 *)(param_1 + 0x1c),iStack_4 + -1,param_2 + -1);
  return 1;
}



undefined4 __thiscall