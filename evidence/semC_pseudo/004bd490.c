void __thiscall FUN_004bd490(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  undefined1 local_566;
  undefined1 local_565;
  int local_564;
  undefined1 local_55f;
  undefined1 local_55e;
  undefined1 local_55d;
  undefined1 local_55c [8];
  undefined1 local_554 [108];
  undefined4 local_4e8;
  undefined4 local_490;
  undefined4 local_36c;
  undefined4 local_368;
  undefined4 local_364;
  undefined4 local_360;
  undefined4 local_35c;
  undefined4 local_358;
  undefined4 local_354;
  undefined4 local_350;
  undefined4 local_34c;
  undefined4 local_348;
  undefined1 local_344;
  undefined1 local_343;
  char local_342;
  char *local_340;
  int local_33c;
  undefined4 local_334 [3];
  undefined4 local_328;
  undefined4 local_324;
  undefined4 local_31c;
  undefined4 local_318;
  undefined4 local_314;
  undefined4 local_310 [3];
  undefined4 local_304 [3];
  undefined4 local_2f8;
  undefined4 local_2b4 [170];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005a10c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00493d90();
  FUN_004b36f0(&local_565);
  local_4 = 0;
  FUN_00492690();
  local_4._0_1_ = 1;
  FUN_005498c0();
  FUN_005498c0();
  FUN_005498c0();
  FUN_005498c0();
  FUN_004024a0(&local_55e);
  local_4._0_1_ = 2;
  FUN_004024a0(&local_55f);
  local_4._0_1_ = 3;
  FUN_004024a0(&local_55d);
  local_4._0_1_ = 4;
  FUN_004024a0(&local_566);
  local_4._0_1_ = 5;
  FUN_005519d0();
  FUN_00498ca0();
  local_4 = CONCAT31(local_4._1_3_,6);
  local_490 = 0;
  local_31c = 0;
  local_4e8 = 0;
  local_360 = 0;
  local_368 = 0;
  local_36c = 0;
  local_34c = 0;
  local_364 = 0;
  local_344 = 0;
  local_343 = 0;
  local_342 = '\0';
  local_324 = 0;
  local_328 = 0;
  local_350 = 0;
  local_354 = 0;
  local_358 = 0;
  local_314 = 0;
  local_35c = 0;
  local_318 = 0x40c00000;
  local_348 = 0;
  local_2f8 = 0;
  FUN_00549a90(0,0);
  FUN_00549bd0(0,0x40240000);
  FUN_005519e0();
  local_4 = 7;
  if ((char **)(param_3 + 0x10) != &local_340) {
    FUN_00403200(*(char **)(param_3 + 0x10),*(undefined4 *)(param_3 + 0x14));
  }
  local_343 = *(undefined1 *)(param_3 + 2);
  if ((undefined4 *)(param_3 + 0x1c) != local_334) {
    FUN_00403200(*(undefined4 *)(param_3 + 0x1c),*(undefined4 *)(param_3 + 0x20));
  }
  if ((undefined4 *)(param_3 + 0x28) != local_310) {
    FUN_00403200(*(undefined4 *)(param_3 + 0x28),*(undefined4 *)(param_3 + 0x2c));
  }
  if ((undefined4 *)(param_3 + 0x34) != local_304) {
    FUN_00403200(*(undefined4 *)(param_3 + 0x34),*(undefined4 *)(param_3 + 0x38));
  }
  FUN_004b48c0(&local_564);
  if (local_564 != *(int *)(param_1 + 0x3a8)) {
    do {
      iVar1 = *(int *)(local_564 + 0x230) - (int)*(char **)(local_564 + 0x22c);
      if (iVar1 == local_33c - (int)local_340) {
        bVar4 = true;
        pcVar2 = *(char **)(local_564 + 0x22c);
        pcVar3 = local_340;
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar4 = *pcVar2 == *pcVar3;
          pcVar2 = pcVar2 + 1;
          pcVar3 = pcVar3 + 1;
        } while (bVar4);
        if ((bVar4) && (*(char *)(local_564 + 0x22a) == local_342)) {
          local_342 = local_342 + '\x01';
        }
      }
      FUN_0043c6c0();
    } while (local_564 != *(int *)(param_1 + 0x3a8));
  }
  local_318 = param_4;
  local_2b4[0] = param_2;
  FUN_0049a750(local_554);
  local_4._0_1_ = 8;
  FUN_0049d240(local_55c,local_2b4);
  local_4 = CONCAT31(local_4._1_3_,7);
  FUN_0048ee50();
  local_4 = 0xffffffff;
  FUN_0048ee50();
  ExceptionList = local_c;
  return;
}


