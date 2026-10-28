undefined4 FUN_0050f5d0(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (DAT_007f2ec0 <= param_1) {
LAB_0050f651:
    puVar4 = (undefined4 *)FUN_00510865();
    *puVar4 = 9;
    return 0xffffffff;
  }
  iVar5 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)((&DAT_007f2dc0)[(int)param_1 >> 5] + 4 + iVar5) & 1) == 0) goto LAB_0050f651;
  FUN_005115b7(param_1);
  if ((*(byte *)((&DAT_007f2dc0)[(int)param_1 >> 5] + 4 + iVar5) & 1) != 0) {
    hFile = (HANDLE)FUN_00511575(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    uVar6 = 0;
    if (DVar2 == 0) goto LAB_0050f646;
    pDVar3 = (DWORD *)FUN_0051086e();
    *pDVar3 = DVar2;
  }
  puVar4 = (undefined4 *)FUN_00510865();
  *puVar4 = 9;
  uVar6 = 0xffffffff;
LAB_0050f646:
  FUN_00511616(param_1);
  return uVar6;
}



// Library Function - Single Match
//  __allmul
// 
// Library: Visual Studio

longlong __allmul(uint param_1,int param_2,uint param_3,int param_4)

{
  if (param_4 == 0 && param_2 == 0) {
    return (ulonglong)param_1 * (ulonglong)param_3;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_2 * param_3 + param_1 * param_4,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}


