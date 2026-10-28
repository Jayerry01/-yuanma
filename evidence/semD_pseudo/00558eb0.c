void __fastcall FUN_00558eb0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined1 local_4c [12];
  undefined1 local_40 [64];
  
  FUN_00479f80(0);
  FUN_00474320(0xff,0,0,0xff);
  FUN_00574080();
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x20)) {
    iVar3 = 0;
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0x354) + 0xa8 + iVar3);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(local_40,local_4c,0);
        FUN_00475400(local_4c,local_40,0);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x2f0;
    } while (iVar2 < *(int *)(param_1 + 0x20));
  }
  FUN_00475400(param_1 + 0x1b8,param_1 + 0x248,0);
  return;
}


