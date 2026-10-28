undefined4 __thiscall FUN_004fcf00(int param_1,float param_2)

{
  undefined4 uVar1;
  float *pfVar2;
  undefined1 *puVar3;
  float local_14;
  undefined1 local_10 [4];
  undefined1 local_c [12];
  
  pfVar2 = &local_14;
  puVar3 = local_10;
  uVar1 = FUN_00501160(local_c);
  FUN_005016d0(uVar1,pfVar2,puVar3);
  FUN_00501730(&local_14);
  FUN_00501730((float *)(param_1 + 0xe0));
  if (ABS(local_14 - *(float *)(param_1 + 0xe0)) <= param_2) {
    return 1;
  }
  return 0;
}


