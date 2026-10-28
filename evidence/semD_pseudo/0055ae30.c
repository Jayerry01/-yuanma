void __thiscall FUN_0055ae30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float local_4c;
  float local_48;
  undefined1 local_40 [48];
  float local_10;
  float local_c;
  undefined4 local_8;
  
  FUN_00477d30(3,&local_4c);
  fVar1 = *(float *)(*(int *)(param_1 + 0x1678) + 0x1e0);
  fVar2 = *(float *)(param_1 + 0xab0);
  fVar3 = *(float *)(param_1 + 0xaa0);
  fVar4 = *(float *)(*(int *)(param_1 + 0x1678) + 0x1e4);
  fVar5 = *(float *)(param_1 + 0xab4);
  fVar6 = *(float *)(param_1 + 0xaa4);
  FUN_00477200();
  local_8 = 0xbf800000;
  local_10 = (local_4c - fVar1) * fVar2 + fVar3;
  local_c = (local_48 - fVar4) * fVar5 + fVar6;
  FUN_004745d0(local_40);
  FUN_00479f80(param_4);
  FUN_0047c2e0(0);
  return;
}


