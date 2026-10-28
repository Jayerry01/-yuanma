void FUN_0042d230(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  
  iVar1 = *(int *)(param_1 + 0xc0);
  if (param_2 == 1) {
    if (*(int *)(iVar1 + 0x80) != 0) {
      iVar2 = *(int *)(iVar1 + 100);
      iVar3 = *(int *)(*(int *)(iVar1 + 0x80) + 0xc0);
      if (iVar2 == 0) {
        *(undefined4 *)(iVar3 + 8) = 0;
        *(float *)(iVar3 + 0xc) = (float)(*(int *)(iVar3 + 4) + -0x28);
        FUN_0042f0c0(*(undefined4 *)(iVar1 + 0x80));
        return;
      }
      if (iVar2 <= *(int *)(iVar1 + 0x4c)) {
        *(undefined4 *)(iVar3 + 8) = 0;
        *(float *)(iVar3 + 0xc) = (float)(*(int *)(iVar3 + 4) + -0x28);
        FUN_0042f0c0(*(undefined4 *)(iVar1 + 0x80));
        return;
      }
      fVar4 = (float)(*(int *)(iVar3 + 4) + -0x28);
      *(float *)(iVar3 + 0xc) = ((float)*(int *)(iVar1 + 0x4c) * fVar4) / (float)iVar2;
      *(float *)(iVar3 + 8) = ((float)*(int *)(iVar1 + 0x5c) * fVar4) / (float)*(int *)(iVar1 + 100)
      ;
      FUN_0042f0c0(*(undefined4 *)(iVar1 + 0x80));
      return;
    }
  }
  else if (*(int *)(iVar1 + 0x84) != 0) {
    iVar2 = *(int *)(*(int *)(iVar1 + 0x84) + 0xc0);
    if (*(int *)(iVar1 + 0x48) == *(int *)(iVar1 + 0x68)) {
      *(undefined4 *)(iVar2 + 8) = 0;
      *(float *)(iVar2 + 0xc) = (float)(*(int *)(iVar2 + 4) + -0x28);
      FUN_0042f0c0(*(undefined4 *)(iVar1 + 0x84));
      return;
    }
    fVar4 = (float)(*(int *)(iVar2 + 4) + -0x28);
    *(float *)(iVar2 + 0xc) =
         ((float)*(int *)(iVar1 + 0x48) * fVar4) / (float)*(int *)(iVar1 + 0x68);
    *(float *)(iVar2 + 8) = ((float)*(int *)(iVar1 + 0x58) * fVar4) / (float)*(int *)(iVar1 + 0x68);
    FUN_0042f0c0(*(undefined4 *)(iVar1 + 0x84));
  }
  return;
}


