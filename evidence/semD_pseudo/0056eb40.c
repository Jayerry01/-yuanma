void FUN_0056eb40(void)

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
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_4;
  
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
  FUN_00475590(5,0);
  iVar1 = 0;
  puVar2 = &local_48;
  do {
    FUN_00477d30(iVar1,&fStack_24);
    fStack_4 = fStack_1c * 20.0;
    fStack_3c = local_30 + fStack_24 * 20.0;
    fStack_38 = fStack_2c + fStack_20 * 20.0;
    fStack_34 = fStack_28 + fStack_4;
    fStack_18 = fStack_3c;
    fStack_14 = fStack_38;
    fStack_10 = fStack_34;
    FUN_00475090(&local_30,&fStack_18,puVar2);
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 4;
  } while (iVar1 < 3);
  FUN_00475590(5,1);
  return;
}


