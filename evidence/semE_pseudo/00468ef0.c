undefined4 __thiscall FUN_00468ef0(int param_1,int param_2)

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
  return puVar1[2];
}


