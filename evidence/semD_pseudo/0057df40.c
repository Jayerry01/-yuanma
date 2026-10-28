undefined4 __thiscall FUN_0057df40(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  uVar1 = param_2;
  FUN_0050a118(local_18,4,3,param_2);
  FUN_0050a118(local_c,4,3,uVar1);
  FUN_0050a118(&param_2,1,1,uVar1);
  if ((char)param_2 != '\x01') {
    FUN_0050ac20(s_Unknow_type_005d2690);
    return 0;
  }
  *param_1 = param_3;
  FUN_0050a118(param_1 + 1,4,1,uVar1);
  FUN_0050a118(*param_1,param_1[1],1,uVar1);
  uVar1 = FUN_0057dfd0();
  return uVar1;
}


