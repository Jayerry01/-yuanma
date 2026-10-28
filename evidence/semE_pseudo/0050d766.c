void FUN_0050d766(undefined **param_1)

{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR_LOOP_005ccbe8 == param_1) {
    PTR_LOOP_005ccbe8 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_005cabc8) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_007f1d6c,0,param_1);
    return;
  }
  DAT_005cabd8 = 0xffffffff;
  return;
}


