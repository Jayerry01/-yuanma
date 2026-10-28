void __fastcall FUN_004832d0(int *param_1)

{
  param_1[0xd9e8] = 0;
  param_1[0xd9e9] = 0;
  if (param_1[0xdb15] != 0) {
    (**(code **)(*param_1 + 0x10))();
    (**(code **)(*param_1 + 0x14))();
    (**(code **)(*(int *)param_1[0xdb15] + 8))((int *)param_1[0xdb15]);
    (**(code **)(*(int *)param_1[0xdb14] + 8))((int *)param_1[0xdb14]);
    param_1[0xdb15] = 0;
    param_1[0xdb14] = 0;
  }
                    // WARNING: Could not recover jumptable at 0x00483322. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(*param_1 + 0x18))();
  return;
}


