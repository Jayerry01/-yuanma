void __thiscall FUN_0056afc0(int param_1,float *param_2)

{
  undefined4 uVar1;
  float *pfVar2;
  int iVar3;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_90 [20];
  undefined1 local_40 [64];
  
  local_ac = 0.0;
  local_a8 = 0.0;
  local_a4 = 0.0;
  if (*(int *)(param_1 + 0x120) != 0) {
    uVar1 = FUN_00476f00(local_40,*(int *)(param_1 + 0x120) + 0x88,param_1 + 0x54,&local_a0);
    FUN_00475220(*(int *)(param_1 + 0x120) + 0x7c,uVar1);
    local_ac = local_a0;
    local_a4 = local_98;
    local_a8 = local_9c;
    pfVar2 = local_90;
    iVar3 = 7;
    do {
      if (pfVar2[-1] < local_ac) {
        local_ac = pfVar2[-1];
      }
      if (*pfVar2 < local_a8) {
        local_a8 = *pfVar2;
      }
      if (pfVar2[1] < local_a4) {
        local_a4 = pfVar2[1];
      }
      pfVar2 = pfVar2 + 3;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  *param_2 = local_ac;
  param_2[1] = local_a8;
  param_2[2] = local_a4;
  return;
}


