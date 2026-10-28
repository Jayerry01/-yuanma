uint __thiscall FUN_0056d200(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)**(undefined4 **)(param_1 + 0x24c);
  while( true ) {
    if (puVar1 == *(undefined4 **)(param_1 + 0x24c)) {
      return (uint)puVar1 & 0xffffff00;
    }
    if (puVar1[2] == param_2) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return CONCAT31((int3)((uint)puVar1 >> 8),1);
}


