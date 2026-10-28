
void __thiscall
FUN_0048f410(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = (**(code **)(*param_1 + 0x140))(*(undefined4 *)(param_2 + 0x8b8));
  if (iVar1 != 0) {
    piVar2 = (int *)FUN_004e18c0();
    iVar1 = (**(code **)(*piVar2 + 0x70))(param_2);
    if (iVar1 == 0) {
      piVar2 = (int *)FUN_004e18c0();
      uVar4 = *(undefined4 *)(param_2 + 0x8b8);
      uVar3 = 0;
    }
    else {
      piVar2 = (int *)FUN_004e18c0();
      uVar4 = *(undefined4 *)(param_2 + 0x8b8);
      uVar3 = *(undefined4 *)(param_2 + 0x8b4);
    }
    (**(code **)(*piVar2 + 0x78))(param_2,uVar3,uVar4);
  }
  FUN_004dbf80(param_2,param_3,param_4,param_5);
  return;
}

