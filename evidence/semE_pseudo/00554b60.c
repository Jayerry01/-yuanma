void __thiscall FUN_00554b60(SOCKET *param_1,char param_2)

{
  if (*param_1 != 0xffffffff) {
    *(char *)(param_1 + 1) = param_2;
    _param_2 = (uint)(param_2 != '\0');
    ioctlsocket(*param_1,-0x7ffb9982,(u_long *)&param_2);
  }
  return;
}


