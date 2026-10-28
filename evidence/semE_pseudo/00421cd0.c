void FUN_00421cd0(LPCSTR param_1,LPCSTR param_2)

{
  int *piVar1;
  
  if ((DAT_005d5a0c != 0) && (piVar1 = *(int **)(DAT_005d5a0c + 0x6ec), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x28))(piVar1);
  }
  MessageBoxA((HWND)0x0,param_2,param_1,0);
  return;
}


