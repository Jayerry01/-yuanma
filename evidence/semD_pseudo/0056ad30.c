void __thiscall FUN_0056ad30(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = *(undefined4 **)(param_2 + 8);
  iVar2 = *(int *)(param_2 + 0xc);
  if (*(char *)(param_1 + 0x124) == '\0') {
    if (*(int *)(iVar2 + 0x1d0) == 0) {
      if (*(int *)(iVar2 + 0x1f8) != 2) goto LAB_0056adac;
      uVar3 = FUN_00476070(0);
      FUN_0057ed30(uVar3);
    }
    else {
      uVar3 = FUN_00476070(0);
      FUN_0057eb20(uVar3);
    }
    FUN_00474410();
    iVar2 = iVar2 + 0x118;
  }
  else {
    FUN_00474410();
    iVar2 = *(int *)(iVar2 + 4) * 0x40 + *(int *)(param_1 + 0x154);
  }
  thunk_FUN_004e8500(iVar2);
LAB_0056adac:
  FUN_00479f80(*puVar1);
  if (*(char *)(puVar1 + 4) != '\0') {
    FUN_00475590(2,0);
  }
  if (*(char *)((int)puVar1 + 0x11) != '\0') {
    FUN_00475820(puVar1[5],puVar1[6]);
  }
  return;
}


