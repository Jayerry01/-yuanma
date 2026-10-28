undefined4 __thiscall FUN_00465f10(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 1;
  puVar1 = (undefined4 *)**(undefined4 **)(param_1 + 8);
  while( true ) {
    if (puVar1 == *(undefined4 **)(param_1 + 8)) {
      return 0;
    }
    if (iVar2 == param_2) break;
    puVar1 = (undefined4 *)*puVar1;
    iVar2 = iVar2 + 1;
  }
  if (*(int *)(param_1 + 0x44) != 0) {
    FUN_00466190(0);
  }
  *(undefined4 *)(param_1 + 0x44) = puVar1[2];
  FUN_00466190(1);
  return 1;
}


