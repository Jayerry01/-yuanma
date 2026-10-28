void __fastcall FUN_00491230(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  iVar1 = param_1[0x898];
  *(undefined1 *)(param_1 + 0x75e) = 1;
  iVar2 = FUN_00463450();
  *(int *)(iVar2 + 0x2e0) = iVar1;
  (**(code **)(*param_1 + 0x3b0))(1);
  pcVar4 = FUN_004d7a70;
  FUN_0044ef10(FUN_004d7a70);
  FUN_00473270(pcVar4);
  iVar1 = *param_1;
  uVar3 = FUN_00485980();
  (**(code **)(iVar1 + 0x10))(uVar3);
  FUN_0055a320(1);
  FUN_0055a8e0(100);
  FUN_0055a920(100,100);
  FUN_0055a9f0(100,100);
  (**(code **)(*param_1 + 0x22c))(0);
  (**(code **)(param_1[0x922] + 0xa0))();
  param_1[0x8ad] = 0;
  (**(code **)(*param_1 + 0x390))(0);
  return;
}


