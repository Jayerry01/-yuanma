undefined4 __thiscall FUN_00467c50(int param_1,int param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  bool bVar7;
  undefined4 *puVar8;
  int local_18;
  undefined1 local_14 [4];
  uint local_10;
  undefined4 local_c;
  
  uVar4 = param_3;
  piVar1 = (int *)(param_1 + 0x10);
  FUN_0049d3c0(&local_18,&param_3);
  puVar8 = *(undefined4 **)(param_1 + 0x54);
  param_3 = 1;
  if (puVar8 == *(undefined4 **)(param_1 + 0x58)) {
    FUN_0046ecb0(puVar8,&param_3);
  }
  else {
    if (puVar8 != (undefined4 *)0x0) {
      *puVar8 = 1;
    }
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 4;
  }
  if (local_18 == *piVar1) {
    iVar2 = *piVar1;
    local_10 = uVar4;
    local_c = param_2;
    bVar7 = true;
    iVar3 = iVar2;
    iVar5 = *(int *)(iVar2 + 4);
    while (iVar5 != 0) {
      bVar7 = uVar4 < *(uint *)(iVar5 + 0x10);
      iVar3 = iVar5;
      if (bVar7) {
        iVar5 = *(int *)(iVar5 + 8);
      }
      else {
        iVar5 = *(int *)(iVar5 + 0xc);
      }
    }
    param_3 = iVar3;
    if (bVar7) {
      if (iVar3 == *(int *)(iVar2 + 8)) {
        if ((iVar3 == iVar2) || (uVar4 < *(uint *)(iVar3 + 0x10))) {
          iVar5 = FUN_0046f3d0(&local_10);
          *(int *)(iVar3 + 8) = iVar5;
          iVar2 = *piVar1;
          if (iVar3 == iVar2) {
            *(int *)(iVar2 + 4) = iVar5;
            *(int *)(*piVar1 + 0xc) = iVar5;
          }
          else if (iVar3 == *(int *)(iVar2 + 8)) {
            *(int *)(iVar2 + 8) = iVar5;
          }
        }
        else {
          iVar5 = FUN_0046f3d0(&local_10);
          *(int *)(iVar3 + 0xc) = iVar5;
          if (iVar3 == *(int *)(*piVar1 + 0xc)) {
            *(int *)(*piVar1 + 0xc) = iVar5;
          }
        }
        *(int *)(iVar5 + 4) = iVar3;
        *(undefined4 *)(iVar5 + 8) = 0;
        *(undefined4 *)(iVar5 + 0xc) = 0;
        FUN_00460be0(iVar5,*piVar1 + 4);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        return 1;
      }
      FUN_0044cf00();
    }
    puVar8 = &param_2;
    if (*(uint *)(param_3 + 0x10) < uVar4) {
      param_2 = CONCAT31(param_2._1_3_,1);
      puVar6 = (undefined4 *)FUN_0046f150(local_14,0,iVar3,&local_10);
    }
    else {
      puVar6 = &param_3;
      param_2 = (uint)param_2._1_3_ << 8;
    }
    FUN_0046ef70(puVar6,puVar8);
    return 1;
  }
  if (*(undefined4 **)(local_18 + 0x14) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(local_18 + 0x14))(1);
  }
  *(int *)(local_18 + 0x14) = param_2;
  return 1;
}


