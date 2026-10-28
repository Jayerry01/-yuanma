bool __fastcall FUN_00553b20(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  ushort uVar3;
  uint *puVar4;
  uint *local_4;
  
  if ((ushort)param_1[3] < 4) {
    return false;
  }
  uVar3 = (ushort)param_1[3] - 4;
  uVar1 = *param_1;
  *(ushort *)(param_1 + 3) = uVar3;
  *param_1 = (uint)uVar3;
  local_4 = param_1;
  FUN_00553960(&local_4,4);
  puVar2 = local_4;
  *param_1 = uVar1;
  FUN_00553a10((int)param_1 + 0xe,(short)param_1[3],local_4);
  puVar4 = (uint *)FUN_00553ab0();
  return puVar2 == puVar4;
}


