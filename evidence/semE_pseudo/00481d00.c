undefined4 __thiscall FUN_00481d00(int param_1,int param_2,undefined4 param_3)

{
  if ((((*(int *)(param_1 + 0xc) != 0) && (-1 < param_2)) && (param_2 < *(int *)(param_1 + 0x4c)))
     && (*(int *)(param_1 + 0x20) != -1)) {
    *(undefined4 *)
     (*(int *)(param_1 + 0x10) * param_2 + *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0xc)) =
         param_3;
    return 1;
  }
  return 0;
}


