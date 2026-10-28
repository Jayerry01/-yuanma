void FUN_0053ec70(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int local_4;
  
  piVar1 = param_1;
  param_1[1] = 0;
  local_4 = FUN_004d5fb0(param_1);
  puVar2 = (undefined4 *)FUN_0053ff70(piVar1,0x54);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_004e8500(piVar1);
    *(undefined4 *)(*piVar1 + 0x14) = 0x36;
    *(undefined4 *)(*piVar1 + 0x18) = 0;
    (**(code **)*piVar1)(piVar1);
  }
  *puVar2 = FUN_0053edb0;
  puVar2[1] = FUN_0053ef00;
  puVar2[2] = FUN_0053efb0;
  puVar2[3] = FUN_0053f050;
  puVar2[4] = FUN_0053f100;
  puVar2[5] = FUN_0053f170;
  puVar2[6] = FUN_0053f1e0;
  puVar2[7] = &LAB_0053f370;
  puVar2[8] = &LAB_0053f560;
  puVar2[9] = FUN_0053f750;
  puVar2[10] = &LAB_0053f850;
  puVar2[0xc] = 1000000000;
  iVar4 = 2;
  puVar2[0xb] = local_4;
  puVar3 = puVar2 + 0x10;
  do {
    puVar3[-2] = 0;
    *puVar3 = 0;
    puVar3 = puVar3 + -1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  puVar2[0x11] = 0;
  puVar2[0x12] = 0;
  puVar2[0x13] = 0x54;
  piVar1[1] = (int)puVar2;
  iVar4 = FUN_00514ee1(s_JPEGMEM_005d1144);
  if (iVar4 != 0) {
    param_1 = (int *)CONCAT31(param_1._1_3_,0x78);
    iVar4 = FUN_00593b0d(iVar4,s__ld_c_005d113c,&local_4,&param_1);
    if (0 < iVar4) {
      if (((char)param_1 == 'm') || ((char)param_1 == 'M')) {
        puVar2[0xb] = local_4 * 1000000;
        return;
      }
      puVar2[0xb] = local_4 * 1000;
    }
  }
  return;
}


