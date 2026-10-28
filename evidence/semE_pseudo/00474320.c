void FUN_00474320(uint param_1,uint param_2,uint param_3,uint param_4)

{
  DAT_005e07d0 = FUN_00475c50(param_1 & 0xff,param_2 & 0xff,param_3 & 0xff,param_4 & 0xff);
  (*(code *)PTR_FUN_005c7c6c)(param_1,param_2,param_3,param_4);
  return;
}



void thunk_FUN_004d5fb0(void)

{
                    // WARNING: Could not recover jumptable at 0x00474380. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)PTR_FUN_005c7ccc)();
  return;
}


