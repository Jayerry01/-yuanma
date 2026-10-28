undefined4 FUN_0046c5d0(int param_1)

{
  char cVar1;
  char *pcVar2;
  char local_14 [20];
  
  local_14[0] = '\0';
  local_14[1] = '\0';
  local_14[2] = '\0';
  local_14[3] = '\0';
  local_14[4] = '\0';
  local_14[5] = '\0';
  local_14[6] = '\0';
  local_14[7] = '\0';
  local_14[8] = '\0';
  local_14[9] = '\0';
  local_14[10] = '\0';
  local_14[0xb] = '\0';
  local_14[0xc] = '\0';
  local_14[0xd] = '\0';
  local_14[0xe] = '\0';
  local_14[0xf] = '\0';
  local_14[0x10] = '\0';
  local_14[0x11] = '\0';
  FUN_00464220(local_14);
  pcVar2 = local_14;
  do {
    cVar1 = *pcVar2;
    pcVar2[param_1 - (int)local_14] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return 1;
}


