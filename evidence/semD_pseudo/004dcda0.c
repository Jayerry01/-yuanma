undefined4 __thiscall FUN_004dcda0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = (**(code **)(*param_2 + 0x134))();
  if (iVar1 != *(int *)(param_1 + 0x18)) {
    piVar3 = *(int **)(param_1 + 0x1c);
    if (piVar3 != *(int **)(param_1 + 0x20)) {
      do {
        if ((*piVar3 == iVar1) && (iVar2 = FUN_0055c300(), iVar2 != 4)) {
          return 0;
        }
        piVar3 = piVar3 + 1;
      } while (piVar3 != *(int **)(param_1 + 0x20));
    }
    (**(code **)(*param_2 + 0x74))(*(undefined4 *)(param_1 + 0x18),1,0,0xbf800000);
  }
  return 0;
}



undefined4 __thiscall