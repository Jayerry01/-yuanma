void __thiscall FUN_00583c20(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  *(int *)(param_1 + 0x274) = param_2;
  *(undefined4 *)(param_1 + 0x91c) = 0;
  if (param_2 != 0) {
    FUN_00480770(param_2 + 0x74);
    FUN_00480770(param_2 + 0xb4);
    iVar1 = FUN_005565e0();
    if (0 < iVar1) {
      do {
        iVar1 = FUN_005598c0(iVar3);
        if (iVar1 != 0) {
          *(int *)(param_1 + 0x28c + *(int *)(param_1 + 0x91c) * 4) = iVar3;
          uVar2 = FUN_005598c0(iVar3);
          *(undefined4 *)(param_1 + 0x278 + *(int *)(param_1 + 0x91c) * 4) = uVar2;
          *(int *)(param_1 + 0x91c) = *(int *)(param_1 + 0x91c) + 1;
        }
        iVar3 = iVar3 + 1;
        iVar1 = FUN_005565e0();
      } while (iVar3 < iVar1);
    }
  }
  return;
}


