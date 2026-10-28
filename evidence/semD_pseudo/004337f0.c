void FUN_004337f0(HANDLE param_1,int *param_2)

{
  int *piVar1;
  HDC hdc;
  HGDIOBJ h;
  int unaff_EBX;
  HDC unaff_retaddr;
  int local_18 [6];
  
  piVar1 = param_2;
  if ((param_2 != (int *)0x0) && (param_1 != (HANDLE)0x0)) {
    GetObjectA(param_1,0x18,local_18);
    (**(code **)(*piVar1 + 0x44))(piVar1,&param_2);
    hdc = CreateCompatibleDC(unaff_retaddr);
    h = SelectObject(hdc,param_1);
    BitBlt(unaff_retaddr,0,0,unaff_EBX,local_18[0],hdc,0,0,0xcc0020);
    SelectObject(hdc,h);
    (**(code **)(*piVar1 + 0x68))(piVar1,unaff_retaddr);
    DeleteObject(hdc);
  }
  return;
}


