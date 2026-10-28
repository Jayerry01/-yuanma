void __fastcall FUN_00578810(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 4) = 0;
  iVar1 = (int)((ulonglong)
                ((longlong)(*(int *)(param_1 + 0xc) - *(int *)(param_1 + 8)) * -0x38e38e39) >> 0x20)
  ;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + ((iVar1 >> 3) - (iVar1 >> 0x1f)) * 0x24;
  return;
}


