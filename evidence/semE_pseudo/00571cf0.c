void __fastcall FUN_00571cf0(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  
  fVar3 = 0.0;
  iVar2 = *(int *)(param_1 + 0x20);
  if (0 < iVar2) {
    pfVar4 = *(float **)(param_1 + 0x28);
    iVar5 = iVar2;
    do {
      fVar3 = fVar3 + *pfVar4;
      pfVar4 = pfVar4 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  iVar5 = 0;
  if (0 < iVar2) {
    do {
      iVar2 = iVar5 * 4;
      iVar1 = iVar5 * 4;
      iVar5 = iVar5 + 1;
      *(float *)(*(int *)(param_1 + 0x28) + iVar1) =
           (1.0 / fVar3) * *(float *)(*(int *)(param_1 + 0x28) + iVar2);
    } while (iVar5 < *(int *)(param_1 + 0x20));
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x005720ec)
// WARNING: Removing unreachable block (ram,0x0057209c)
// WARNING: Removing unreachable block (ram,0x005720ae)
// WARNING: Removing unreachable block (ram,0x00571fab)
// WARNING: Removing unreachable block (ram,0x00571fb3)
// WARNING: Removing unreachable block (ram,0x00571f11)
// WARNING: Removing unreachable block (ram,0x00571f15)
// WARNING: Removing unreachable block (ram,0x00572098)
// WARNING: Removing unreachable block (ram,0x005720a3)
// WARNING: Removing unreachable block (ram,0x005720f0)
// WARNING: Globals starting with '_' overlap smaller symbols at the same address
