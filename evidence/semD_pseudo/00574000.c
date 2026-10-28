void __fastcall FUN_00574000(int param_1)

{
  int iVar1;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  FUN_00477d30(3,local_c);
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x34)) {
    do {
      FUN_00477d30(3,local_18);
      FUN_00475090(local_c,local_18,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x34));
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x34)) {
    do {
      FUN_00574000();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x34));
  }
  return;
}


