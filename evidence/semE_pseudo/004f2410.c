undefined4 __thiscall FUN_004f2410(int *param_1,uint param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  iVar3 = (**(code **)(*param_1 + 0x134))();
  if (iVar3 != 0) {
    piVar1 = *(int **)(iVar3 + 0xb0);
    uVar5 = 0;
    piVar4 = (int *)*piVar1;
    if (piVar4 != piVar1) {
      do {
        piVar4 = (int *)*piVar4;
        uVar5 = uVar5 + 1;
      } while (piVar4 != piVar1);
      if (param_2 < uVar5) {
        puVar2 = (undefined4 *)**(undefined4 **)(iVar3 + 0xb0);
        for (; param_2 != 0; param_2 = param_2 - 1) {
          puVar2 = (undefined4 *)*puVar2;
        }
        return puVar2[0xc];
      }
    }
  }
  return 0;
}


