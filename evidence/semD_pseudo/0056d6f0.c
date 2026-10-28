void FUN_0056d6f0(void)

{
  undefined4 *puVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [12];
  
  local_24 = 0;
  local_20 = 0;
  local_1c = 0x3f800000;
  FUN_00477d30(0,&local_30);
  puVar1 = (undefined4 *)FUN_0047edc0(local_c,&local_24,&local_30);
  local_18 = *puVar1;
  local_14 = puVar1[1];
  local_10 = puVar1[2];
  puVar1 = (undefined4 *)FUN_0047edc0(local_c,&local_18,&local_24);
  local_30 = *puVar1;
  local_2c = puVar1[1];
  local_28 = puVar1[2];
  FUN_00477b90(0,&local_30);
  FUN_00477b90(1,&local_18);
  FUN_00477b90(2,&local_24);
  return;
}


