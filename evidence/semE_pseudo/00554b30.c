void __thiscall FUN_00554b30(SOCKET *param_1,char param_2)

{
  if (*param_1 != 0xffffffff) {
    _param_2 = (uint)(param_2 != '\0');
    setsockopt(*param_1,0xffff,0x20,&param_2,4);
  }
  return;
}


