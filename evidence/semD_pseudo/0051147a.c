undefined4 FUN_0051147a(uint param_1,HANDLE param_2)

{
  undefined4 *puVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if (param_1 < DAT_007f2ec0) {
    iVar2 = (param_1 & 0x1f) * 0x24;
    if (*(int *)((&DAT_007f2dc0)[(int)param_1 >> 5] + iVar2) == -1) {
      if (DAT_005ca6c4 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_005114d3;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_005114d3:
      *(HANDLE *)((&DAT_007f2dc0)[(int)param_1 >> 5] + iVar2) = param_2;
      return 0;
    }
  }
  puVar1 = (undefined4 *)FUN_00510865();
  *puVar1 = 9;
  puVar1 = (undefined4 *)FUN_0051086e();
  *puVar1 = 0;
  return 0xffffffff;
}


