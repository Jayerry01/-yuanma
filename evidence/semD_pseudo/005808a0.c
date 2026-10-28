void FUN_005808a0(int param_1)

{
  undefined1 local_100 [128];
  undefined1 local_80 [128];
  
  DAT_0072bad4 = DAT_0072bad4 + 1;
  if (param_1 != 0) {
    FUN_00509ddb(local_80,param_1,&stack0x00000008);
    FUN_00508ae6(local_100,s__d___s_005d2e48,DAT_005d297c,local_80);
    FUN_0050ac20(&DAT_005d1138,local_100);
    FUN_00569cb0(local_100);
  }
  return;
}


