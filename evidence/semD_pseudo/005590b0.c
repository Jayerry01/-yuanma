void FUN_005590b0(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 local_48;
  undefined1 local_47;
  undefined1 local_46;
  undefined1 local_45;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_4;
  
  FUN_00477d30(3,&local_30);
  local_48 = 0xff;
  local_47 = 0;
  local_46 = 0;
  local_45 = 0xff;
  local_44 = 0;
  local_43 = 0xff;
  local_42 = 0;
  local_41 = 0xff;
  local_40 = 0;
  local_3f = 0;
  local_3e = 0xff;
  local_3d = 0xff;
  FUN_00479f80(0);
  iVar1 = 0;
  puVar2 = &local_48;
  do {
    FUN_00477d30(iVar1,&local_24);
    local_4 = local_1c * 15.0;
    local_3c = local_30 + local_24 * 15.0;
    local_38 = local_2c + local_20 * 15.0;
    local_34 = local_28 + local_4;
    local_18 = local_3c;
    local_14 = local_38;
    local_10 = local_34;
    FUN_00475090(&local_30,&local_18,puVar2);
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 4;
  } while (iVar1 < 3);
  return;
}


