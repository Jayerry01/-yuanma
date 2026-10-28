char * FUN_0050b44a(char *param_1)

{
  _SYSTEMTIME local_14;
  
  GetLocalTime(&local_14);
  param_1[8] = '\0';
  param_1[5] = ':';
  param_1[2] = ':';
  *param_1 = (char)((ulonglong)(uint)local_14.wHour / 10) + '0';
  param_1[1] = (char)((ulonglong)(uint)local_14.wHour % 10) + '0';
  param_1[3] = (char)((ulonglong)local_14.wMinute / 10) + '0';
  param_1[4] = (char)((ulonglong)local_14.wMinute % 10) + '0';
  param_1[6] = (char)((ulonglong)local_14.wSecond / 10) + '0';
  param_1[7] = (char)((ulonglong)local_14.wSecond % 10) + '0';
  return param_1;
}


