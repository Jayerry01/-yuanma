void FUN_00540670(int param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  
  puVar2 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x74);
  *(undefined4 **)(param_1 + 0x188) = puVar2;
  *puVar2 = &LAB_00540780;
  puVar2[2] = FUN_00540800;
  puVar2[0x1c] = 0;
  if (param_2 == '\0') {
    iVar4 = (**(code **)(*(int *)(param_1 + 4) + 4))(param_1,1,0x500);
    piVar7 = puVar2 + 8;
    iVar5 = 10;
    do {
      *piVar7 = iVar4;
      piVar7 = piVar7 + 1;
      iVar4 = iVar4 + 0x80;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    puVar2[1] = &LAB_00540a90;
    puVar2[3] = &LAB_00540850;
    puVar2[4] = 0;
    return;
  }
  _param_2 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    piVar7 = (int *)(*(int *)(param_1 + 0xc4) + 0xc);
    puVar6 = puVar2 + 0x12;
    do {
      iVar4 = *piVar7;
      iVar5 = iVar4;
      if (*(char *)(param_1 + 200) != '\0') {
        iVar5 = iVar4 * 3;
      }
      iVar1 = *(int *)(param_1 + 4);
      uVar3 = FUN_0053e5c0(piVar7[5],iVar4,iVar5);
      uVar3 = FUN_0053e5c0(piVar7[4],piVar7[-1],uVar3);
      uVar3 = (**(code **)(iVar1 + 0x14))(param_1,1,1,uVar3);
      *puVar6 = uVar3;
      _param_2 = _param_2 + 1;
      puVar6 = puVar6 + 1;
      piVar7 = piVar7 + 0x15;
    } while (_param_2 < *(int *)(param_1 + 0x24));
  }
  puVar2[1] = &LAB_00540aa0;
  puVar2[3] = &LAB_00540c90;
  puVar2[4] = puVar2 + 0x12;
  return;
}


