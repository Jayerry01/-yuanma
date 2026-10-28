undefined4 __thiscall FUN_00584c50(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0x274) != 0) {
    iVar1 = FUN_005565d0();
    iVar2 = FUN_005565e0();
    if ((-1 < param_2) && (param_2 <= iVar1 + iVar2)) {
      iVar3 = FUN_005565d0();
      if (param_2 < iVar3) {
        uVar4 = FUN_00556630(param_2);
        return uVar4;
      }
      if (param_2 < iVar1 + iVar2) {
        iVar1 = FUN_005565d0();
        uVar4 = FUN_00556650(param_2 - iVar1);
        return uVar4;
      }
    }
  }
  return 0;
}


