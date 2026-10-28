void __fastcall FUN_0057d150(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar2 = *(float *)(*param_1 + 0x10);
  fVar1 = *(float *)(*param_1 + 0x1c);
  iVar3 = _rand();
  param_1[1] = (int)((float)iVar3 * 3.051851e-05 * (fVar1 - fVar2) + fVar2);
  fVar2 = *(float *)(*param_1 + 0x14);
  fVar1 = *(float *)(*param_1 + 0x20);
  iVar3 = _rand();
  param_1[2] = (int)((float)iVar3 * 3.051851e-05 * (fVar1 - fVar2) + fVar2);
  fVar2 = *(float *)(*param_1 + 0x18);
  fVar1 = *(float *)(*param_1 + 0x24);
  iVar3 = _rand();
  param_1[3] = (int)((float)iVar3 * 3.051851e-05 * (fVar1 - fVar2) + fVar2);
  fVar2 = -*(float *)(*param_1 + 400);
  fVar1 = *(float *)(*param_1 + 400);
  iVar3 = _rand();
  param_1[4] = (int)((float)iVar3 * 3.051851e-05 * (fVar1 - fVar2) + fVar2);
  fVar2 = -*(float *)(*param_1 + 400);
  fVar1 = *(float *)(*param_1 + 400);
  iVar3 = _rand();
  param_1[5] = (int)((float)iVar3 * 3.051851e-05 * (fVar1 - fVar2) + fVar2);
  fVar2 = -*(float *)(*param_1 + 0x194);
  fVar1 = *(float *)(*param_1 + 0x198);
  iVar3 = _rand();
  param_1[6] = (int)((float)iVar3 * 3.051851e-05 * (fVar1 - fVar2) + fVar2);
  fVar2 = *(float *)(*param_1 + 0x178);
  fVar1 = *(float *)(*param_1 + 0x17c);
  iVar3 = _rand();
  param_1[7] = 0;
  param_1[9] = (int)((float)iVar3 * 3.051851e-05 * (fVar1 - fVar2) + fVar2);
  fVar2 = *(float *)(*param_1 + 0x180);
  fVar1 = *(float *)(*param_1 + 0x184);
  iVar3 = _rand();
  param_1[8] = (int)((float)iVar3 * 3.051851e-05 * (fVar1 - fVar2) + fVar2);
  return;
}


