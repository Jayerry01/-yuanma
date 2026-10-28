uint FUN_005310c0(undefined4 param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  puVar1 = DAT_007232a8;
  uVar2 = FUN_00530e70(param_1);
  uVar3 = uVar2;
  if (uVar2 != 0) {
    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[2]) {
      uVar3 = FUN_0050a9d0(uVar2,*puVar1);
      if (uVar3 == 0) {
        iVar4 = (*(code *)puVar1[1])(param_1);
        if (iVar4 != 0) {
          uVar3 = FUN_00530d00(iVar4);
          return uVar3 & 0xffffff00;
        }
        return 1;
      }
    }
  }
  return uVar3 & 0xffffff00;
}


