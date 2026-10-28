undefined4 __thiscall FUN_00582c60(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_0058a680(param_1 + 9,param_2);
  FUN_00509fa2(param_1[0x7b] + 8,4,1,param_2);
  FUN_00509fa2(param_1[0x7b] + 0xc,4,1,param_2);
  FUN_00509fa2(param_1[0x7b] + 4,4,1,param_2);
  FUN_00509fa2(param_1[0x7b] + 0x24,4,1,param_2);
  FUN_0058a670(param_1[0x7b] + 0xf4,param_2);
  FUN_0058a670(param_1[0x7b] + 0x100,param_2);
  (*(code *)**(undefined4 **)(param_1[0x7b] + 0x38))(param_2);
  (**(code **)(*param_1 + 4))(param_2);
  FUN_00509fa2(param_1[0x7b] + 0x2c,4,1,param_2);
  iVar1 = *(int *)(param_1[0x7b] + 0x2c);
  if (iVar1 != 0) {
    FUN_00509fa2(*(undefined4 *)(param_1[0x7b] + 0x30),1,iVar1,param_2);
  }
  return 1;
}


