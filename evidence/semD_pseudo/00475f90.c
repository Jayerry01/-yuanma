void FUN_00475f90(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_40 [64];
  
  puVar1 = &DAT_005e07d4;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_1;
    param_1 = param_1 + 1;
    puVar1 = puVar1 + 1;
  }
  FUN_00477220();
  puVar1 = (undefined4 *)FUN_00477ad0(local_40);
  puVar3 = &DAT_005e0814;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_00477d30(0,&DAT_005e0860);
  _DAT_005e0860 = -_DAT_005e0860;
  _DAT_005e0864 = -_DAT_005e0864;
  _DAT_005e0868 = -_DAT_005e0868;
  FUN_00477d30(1,&DAT_005e086c);
  FUN_00477d30(2,&DAT_005e0854);
  _DAT_005e0854 = -_DAT_005e0854;
  _DAT_005e0858 = -_DAT_005e0858;
  _DAT_005e085c = -_DAT_005e085c;
  FUN_00477d30(3,&DAT_005e0878);
  FUN_00475cf0();
  return;
}


