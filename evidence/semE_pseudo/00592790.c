undefined4 * __thiscall FUN_00592790(undefined4 *param_1,undefined4 param_2)

{
  FUN_005778a0(param_2,0);
  *param_1 = &PTR_FUN_005b365c;
  param_1[1] = 0x19;
  return param_1;
}



void __fastcall thunk_FUN_005779e0(undefined4 *param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 *extraout_ECX;
  undefined4 *extraout_ECX_00;
  uint uVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  puStack_8 = &LAB_005a60d8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_005ae258;
  uStack_4 = 0;
  cVar2 = FUN_00577880(param_1[6]);
  if ((cVar2 == '\0') && (extraout_ECX != (undefined4 *)0x0)) {
    (**(code **)*extraout_ECX)(1);
    param_1[6] = 0;
  }
  cVar2 = FUN_00577880(param_1[7]);
  if ((cVar2 == '\0') && (extraout_ECX_00 != (undefined4 *)0x0)) {
    (**(code **)*extraout_ECX_00)(1);
    param_1[7] = 0;
  }
  *param_1 = &PTR_LAB_005ab82c;
  piVar1 = (int *)param_1[3];
  uStack_4 = 0xffffffff;
  uVar3 = param_1[5] - (int)piVar1;
  if ((piVar1 != (int *)0x0) && (uVar3 != 0)) {
    if (0x80 < uVar3) {
      FUN_005089fd(piVar1);
      ExceptionList = pvStack_c;
      return;
    }
    FUN_00402330();
    *piVar1 = *(int *)(&DAT_005d59a4 + (uVar3 + 7 >> 3) * 4);
    *(int **)(&DAT_005d59a4 + (uVar3 + 7 >> 3) * 4) = piVar1;
    FUN_00443330();
  }
  ExceptionList = pvStack_c;
  return;
}


