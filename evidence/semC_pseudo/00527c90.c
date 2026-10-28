void FUN_00527c90(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  LPWAVEHDR pwh;
  undefined4 *puVar3;
  
  if (param_1 != (undefined4 *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0072c200);
    if (param_1[0x6e] != 0) {
      timeKillEvent(param_1[0x6e]);
    }
    if (param_1[0x49] == 0) {
      DAT_00667a34 = 1;
      WaitForSingleObjectEx(DAT_00667a38,5000,0);
      WaitForSingleObjectEx(DAT_00667a3c,5000,0);
      waveOutReset((HWAVEOUT)param_1[0x4d]);
      pwh = (LPWAVEHDR)(param_1 + 0x4e);
      iVar2 = 4;
      do {
        waveOutUnprepareHeader((HWAVEOUT)param_1[0x4d],pwh,0x20);
        FUN_005089fd(pwh->lpData);
        pwh = pwh + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      waveOutClose((HWAVEOUT)param_1[0x4d]);
      param_1[0x4d] = 0;
      CloseHandle(DAT_00667a40);
      DAT_00667a40 = (HANDLE)0x0;
      if (DAT_00667a38 != (HANDLE)0x0) {
        CloseHandle(DAT_00667a38);
        DAT_00667a38 = (HANDLE)0x0;
      }
      if (DAT_00667a3c != (HANDLE)0x0) {
        CloseHandle(DAT_00667a3c);
        DAT_00667a3c = (HANDLE)0x0;
      }
    }
    else {
      piVar1 = (int *)param_1[0x4c];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      piVar1 = (int *)param_1[0x4b];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      piVar1 = (int *)param_1[0x4a];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      piVar1 = (int *)param_1[0x49];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      CoUninitialize();
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_0072c200);
    puVar3 = param_1;
    for (iVar2 = 0x6f; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    FUN_005089fd(param_1);
    return;
  }
  FUN_00525630();
  return;
}


