void __thiscall FUN_0047f9e0(int param_1,int param_2,int param_3)

{
  if ((*(int *)(param_1 + 0xa0) != 0) &&
     ((*(int *)(param_1 + 0x88) != param_2 || (*(int *)(param_1 + 0x8c) != param_3)))) {
    FUN_0052c070(*(undefined4 *)(param_1 + 0x80));
    FUN_0052f7a0(0x2600,0x2601);
    FUN_0052daa0(param_2,param_3,1);
  }
  if ((*(int *)(param_1 + 0xa4) != 0) &&
     ((*(int *)(param_1 + 0x90) != param_2 || (*(int *)(param_1 + 0x94) != param_3)))) {
    FUN_0052c070(*(undefined4 *)(param_1 + 0x84));
    FUN_0052f7a0(0x2600,0x2601);
    FUN_0052daa0(param_2,param_3,1);
  }
  return;
}


