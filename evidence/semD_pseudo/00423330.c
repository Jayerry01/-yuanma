void FUN_00423330(void)

{
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  undefined4 local_64 [20];
  undefined4 local_14;
  
  local_74 = *(int *)(DAT_007e28a4 + 4);
  local_70 = *(int *)(DAT_007e28a4 + 8);
  if (DAT_005c431c == 0) {
    local_70 = local_70 * 2;
  }
  local_6c = *(int *)(DAT_007e28a4 + 0xc) + *(int *)(DAT_007e28a4 + 4);
  if (DAT_005c431c == 0) {
    local_68 = (*(int *)(DAT_007e28a4 + 0x10) + *(int *)(DAT_007e28a4 + 8)) * 2;
  }
  else {
    local_68 = *(int *)(DAT_007e28a4 + 0x10) + *(int *)(DAT_007e28a4 + 8);
  }
  if (local_70 < 0) {
    local_70 = 0;
  }
  if (local_74 < 0) {
    local_74 = 0;
  }
  if (*(int *)(DAT_005d5a0c + 0x690) < local_68) {
    local_68 = *(int *)(DAT_005d5a0c + 0x690);
  }
  if (*(int *)(DAT_005d5a0c + 0x68c) < local_6c) {
    local_6c = *(int *)(DAT_005d5a0c + 0x68c);
  }
  local_64[0] = 100;
  local_14 = *(undefined4 *)(DAT_007e28a4 + 0x2c);
  do {
    DAT_007e2768 = 0x8876021c;
    DAT_007e2768 = (**(code **)(**(int **)(DAT_005d5a0c + 0x6f4) + 0x14))
                             (*(int **)(DAT_005d5a0c + 0x6f4),&local_74,0,0,0x400,local_64);
  } while (DAT_007e2768 == -0x7789fde4);
  return;
}


