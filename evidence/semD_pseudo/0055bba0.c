void __thiscall FUN_0055bba0(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_c;
  int local_8;
  int local_4;
  
  iVar3 = param_2;
  piVar4 = (int *)**(int **)(param_1 + 0x167c);
  do {
    if (piVar4 == *(int **)(param_1 + 0x167c)) {
LAB_0055bbef:
      local_c = iVar3;
      local_8 = param_3;
      local_4 = 0;
      FUN_004db820(&param_2);
      piVar4 = (int *)FUN_0055bc80(&local_c);
      *piVar4 = param_2;
      piVar4[1] = *(int *)(param_2 + 4);
      **(int **)(param_2 + 4) = (int)piVar4;
      *(int **)(param_2 + 4) = piVar4;
      return;
    }
    local_8 = piVar4[3];
    local_4 = piVar4[4];
    if (piVar4[2] == param_2) {
      piVar1 = (int *)piVar4[1];
      iVar2 = *piVar4;
      *piVar1 = iVar2;
      *(int **)(iVar2 + 4) = piVar1;
      FUN_00402e90(piVar4,0x14);
      goto LAB_0055bbef;
    }
    piVar4 = (int *)*piVar4;
  } while( true );
}


