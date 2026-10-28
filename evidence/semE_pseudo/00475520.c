void FUN_00475520(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  if ((((param_2 != 0) && (param_3 != 0)) && (param_4 != 0)) && ((param_5 != 0 && (param_6 != 0))))
  {
    (*(code *)PTR_FUN_005c7c88)(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return;
}



void thunk_FUN_004e8500(void)

{
                    // WARNING: Could not recover jumptable at 0x00475560. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR_FUN_005c7c84)();
  return;
}



void thunk_FUN_004e8500(void)

{
                    // WARNING: Could not recover jumptable at 0x00475570. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR_FUN_005c7c90)();
  return;
}



void thunk_FUN_00475590(int param_1,int param_2)

{
  switch(param_1) {
  case 0:
    DAT_005e043c = param_2;
    break;
  case 1:
    DAT_005e0448 = param_2;
    break;
  case 2:
    DAT_005e0454 = param_2;
    break;
  case 3:
    DAT_005e045c = param_2;
    break;
  case 4:
    DAT_005e0460 = param_2;
    break;
  case 5:
    (&DAT_005e046c)[DAT_005e0490] = param_2;
    break;
  case 6:
    DAT_005e04a4 = param_2;
    break;
  case 7:
    DAT_005e0418 = param_2;
    break;
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    *(int *)(&DAT_005e03fc + param_1 * 4) = param_2;
    break;
  case 0x10:
    DAT_005e04c8 = param_2;
    break;
  case 0x11:
    DAT_005e04cc = param_2;
    break;
  case 0x12:
    DAT_005e0464 = param_2;
    break;
  case 0x13:
    DAT_005e04d0 = param_2;
    break;
  case 0x14:
    DAT_005e0498 = param_2;
    break;
  case 0x15:
    DAT_005e049c = param_2;
    break;
  case 0x16:
    DAT_005e04d4 = param_2;
    break;
  case 0x18:
    *(undefined4 *)(&DAT_005e04b8 + DAT_005e0490 * 4) = *(undefined4 *)(&DAT_005c7d1c + param_2 * 4)
    ;
  }
                    // WARNING: Could not recover jumptable at 0x00475646. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR_FUN_005c7c94)();
  return;
}


