void __fastcall FUN_004f5890(int *param_1)

{
  int iVar1;
  undefined1 local_c [12];
  
  param_1[0x16] = 200;
  param_1[0x17] = 200;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  FUN_004059e0(5);
  iVar1 = FUN_00405df0(0);
  param_1[0x1c] = iVar1;
  FUN_00407c10(iVar1,0,local_c,0);
  FUN_00549430(param_1[0x16],param_1[0x17]);
  (**(code **)(*param_1 + 0x48))();
  return;
}


