void FUN_004bff20(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_004c3730(param_1);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) != 0)) {
    piVar2 = (int *)FUN_00487830();
    (**(code **)(*piVar2 + 0x248))(*(undefined4 *)(iVar1 + 0xc));
    FUN_004fb730();
  }
  return;
}


