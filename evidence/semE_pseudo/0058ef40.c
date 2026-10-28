void __thiscall FUN_0058ef40(int param_1,float param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  fVar1 = *(float *)(param_3 + 0x28);
  fVar2 = *(float *)(param_3 + 0x2c);
  iVar5 = *(int *)(param_3 + 8);
  fVar3 = *(float *)(iVar5 + 0x28);
  fVar4 = *(float *)(iVar5 + 0x2c);
  *(float *)(param_1 + 0x18) = param_2 * *(float *)(param_3 + 0x24) + *(float *)(iVar5 + 0x24);
  *(float *)(param_1 + 0x1c) = param_2 * fVar1 + fVar3;
  *(float *)(param_1 + 0x20) = param_2 * fVar2 + fVar4;
  return;
}


