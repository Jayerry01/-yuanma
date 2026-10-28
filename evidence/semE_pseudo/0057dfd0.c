int __fastcall FUN_0057dfd0(int *param_1)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint local_4;
  
  iVar4 = 0;
  param_1[2] = 0;
  if (0 < param_1[1]) {
    do {
      bVar2 = *(byte *)(*param_1 + iVar4);
      local_4 = (uint)bVar2;
      if (bVar2 == 0xaa) {
        pcVar1 = (char *)(*param_1 + 1 + iVar4);
        iVar4 = iVar4 + 1;
        if (*pcVar1 == '\0') {
          local_4 = 0xaa;
LAB_0057e004:
          iVar3 = 0;
          do {
            if ((local_4 & 1 << ((byte)iVar3 & 0x1f)) != 0) {
              param_1[2] = param_1[2] + 1;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < 8);
        }
      }
      else if (bVar2 != 0) goto LAB_0057e004;
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_1[1]);
  }
  return param_1[2];
}


