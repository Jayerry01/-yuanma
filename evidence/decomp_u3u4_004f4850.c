
void __thiscall FUN_004f4850(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  switch(param_3) {
  case 0x10:
    piVar1 = (int *)FUN_00487830();
    uVar2 = 0x1000;
    goto LAB_004f48c9;
  case 0x11:
    piVar1 = (int *)FUN_00487830();
    puVar3 = &uStack_4;
    (**(code **)(*piVar1 + 0x2e8))(0x1000,puVar3);
    uVar2 = 0;
    break;
  case 0x12:
    piVar1 = (int *)FUN_00487830();
    uVar2 = 0x1200;
LAB_004f48c9:
    puVar3 = &uStack_4;
    (**(code **)(*piVar1 + 0x2e8))(uVar2,puVar3);
    uVar2 = 1;
    break;
  case 0x13:
    piVar1 = (int *)FUN_00487830();
    puVar3 = &uStack_4;
    (**(code **)(*piVar1 + 0x2e8))(0x1200,puVar3);
    uVar2 = 0;
    break;
  default:
    goto switchD_004f4868_default;
  }
  (**(code **)(*param_1 + 4))(uStack_4,puVar3,uVar2);
switchD_004f4868_default:
  return;
}

