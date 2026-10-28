undefined4 __thiscall FUN_00581500(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)**(undefined4 **)(param_1 + 0x260);
  while( true ) {
    if (puVar1 == *(undefined4 **)(param_1 + 0x260)) {
      return 0;
    }
    if (puVar1[2] == param_2) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return 1;
}


