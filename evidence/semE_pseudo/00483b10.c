bool __thiscall FUN_00483b10(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    uVar2 = *(undefined4 *)(param_2 + 0x2c);
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0x36c54) + 0xf4))
                    (*(int **)(param_1 + 0x36c54),DAT_005e0490,uVar2);
  return iVar1 == 0;
}


