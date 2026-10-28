void FUN_00407670(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined1 local_100 [16];
  undefined1 local_f0 [16];
  undefined1 local_e0 [16];
  undefined1 local_d0 [16];
  undefined1 local_c0 [64];
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  if ((param_2 == param_4) && (param_3 == param_5)) {
    FUN_00430c40(param_1);
    return;
  }
  FUN_00407b50(local_d0,param_2,4);
  FUN_00407b50(local_f0,param_3,4);
  FUN_00407b50(local_100,param_4,4);
  FUN_00407b50(local_e0,param_5,4);
  FUN_00407760(local_40,local_d0,local_f0);
  FUN_00407760(local_c0,local_100,local_e0);
  FUN_004315e0(local_c0,local_80);
  FUN_004312e0(param_1,local_40,local_80);
  return;
}


