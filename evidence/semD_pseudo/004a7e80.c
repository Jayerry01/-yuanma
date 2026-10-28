undefined4 __thiscall FUN_004a7e80(int param_1,undefined4 param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + -0x30);
  iVar2 = (**(code **)(*piVar1 + 0x80))(param_2,param_3 & 0xf,param_3 & 0xf0,param_3 & 0xf00);
  if (iVar2 == 0) {
    return 0;
  }
  if ((param_3 & 0xf000) == 0x1000) {
    (**(code **)(*piVar1 + 0x8c))(1,1);
  }
  else if ((param_3 & 0xf000) == 0x2000) {
    (**(code **)(*piVar1 + 0x8c))(0,1);
    return 1;
  }
  return 1;
}


