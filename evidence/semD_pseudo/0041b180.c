void FUN_0041b180(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_7c [24];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint local_14;
  
  if ((DAT_005d5a0c != 0) && (*(int *)(DAT_005d5a0c + 0x6f8) == 0)) {
    puVar3 = local_7c;
    for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    local_7c[0] = 0x7c;
    local_7c[1] = 7;
    local_14 = 0x800;
    local_7c[3] = *(undefined4 *)(DAT_005d5a0c + 0x68c);
    local_7c[2] = *(undefined4 *)(DAT_005d5a0c + 0x690);
    (**(code **)(**(int **)(DAT_005d5a0c + 0x6ec) + 0x18))
              (*(int **)(DAT_005d5a0c + 0x6ec),local_7c,DAT_005d5a0c + 0x6f8,0);
    if (*(int *)(DAT_005d5a0c + 0x6f8) != 0) {
      if (DAT_007eabe0 == 0x10) {
        uStack_18 = *(undefined4 *)(DAT_005d5a0c + 0x6f8);
        local_14 = (uint)*(uint3 *)(DAT_005d5a0c + 0x70c);
        uStack_1c = 0x41b256;
        uVar1 = FUN_004219f0();
        *(undefined4 *)(DAT_005d5a0c + 0x704) = uVar1;
      }
      return;
    }
    FUN_00410c60(s_Can_t_create_interface_buffer_fo_005c48c0);
  }
  return;
}


