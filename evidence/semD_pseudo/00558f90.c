void __thiscall FUN_00558f90(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if ((*(int *)(param_1 + 0x32c) == 0) && (param_2 != 0)) {
    FUN_00559480();
  }
  iVar1 = *(int *)(param_1 + 0x380);
  FUN_00474e90(4);
  if (*(int *)(param_1 + 0x68) != 0) {
    FUN_00475590(1,1);
    FUN_00475950(&DAT_005c7df8,&DAT_005c7df0);
  }
  param_2 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    piVar3 = (int *)(iVar1 + 0x1c);
    do {
      iVar1 = 0;
      if (0 < piVar3[3]) {
        iVar2 = piVar3[4] + 0x84;
        do {
          FUN_00475980(iVar2);
          FUN_00475520(0,piVar3[2],piVar3[-3],*piVar3 + *(int *)(iVar2 + -0x18) * 2,
                       *(undefined4 *)(iVar2 + -0x14),0xffffffff);
          FUN_00475a60(iVar2);
          iVar1 = iVar1 + 1;
          iVar2 = iVar2 + 0xac;
        } while (iVar1 < piVar3[3]);
      }
      param_2 = param_2 + 1;
      piVar3 = piVar3 + 0xf;
    } while (param_2 < *(int *)(param_1 + 4));
  }
  if (*(int *)(param_1 + 0x68) != 0) {
    FUN_00475590(1,0);
  }
  return;
}


