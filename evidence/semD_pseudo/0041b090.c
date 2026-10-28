void FUN_0041b090(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 unaff_EDI;
  undefined4 local_7c [4];
  undefined4 uStack_6c;
  
  if (DAT_005d5a0c != 0) {
    puVar1 = local_7c;
    for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    }
    local_7c[0] = 0x7c;
    DAT_007e2768 = (**(code **)(**(int **)(DAT_005d5a0c + 0x6f8) + 100))
                             (*(int **)(DAT_005d5a0c + 0x6f8),0,local_7c,0,0);
    if (DAT_007e2768 != 0) {
      (**(code **)(**(int **)(DAT_005d5a0c + 0x6f8) + 0x80))(*(int **)(DAT_005d5a0c + 0x6f8),0);
      FUN_00410c60(s_Can_t_lock_interface_buffer_for_g_005c488c);
      return;
    }
    DAT_007e2c88 = uStack_6c;
    DAT_007e2708 = 0;
    DAT_007e270c = 0;
    _DAT_007e232c = *(undefined4 *)(DAT_005d5a0c + 0x690);
    _DAT_007e0414 = *(undefined4 *)(DAT_005d5a0c + 0x68c);
    DAT_007e2768 = 0;
    DAT_007e28b0 = unaff_EDI;
  }
  return;
}


