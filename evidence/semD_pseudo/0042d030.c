void FUN_0042d030(void)

{
  char cVar1;
  int iVar2;
  HANDLE hFindFile;
  BOOL BVar3;
  char *pcVar4;
  char *pcVar5;
  char local_1c0 [128];
  _WIN32_FIND_DATAA local_140;
  
  iVar2 = 0;
  do {
    cVar1 = (&DAT_007dd980)[iVar2];
    local_1c0[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  iVar2 = -1;
  pcVar4 = local_1c0;
  do {
    pcVar5 = pcVar4;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  *(undefined4 *)(pcVar5 + -1) = DAT_005c68b8;
  DAT_005d5b10 = 0;
  hFindFile = FindFirstFileA(local_1c0,&local_140);
  if (hFindFile == (HANDLE)0xffffffff) {
    DAT_005d5b10 = 0;
    return;
  }
  do {
    if (local_140.dwFileAttributes != 0x10) {
      DAT_005d5b10 = 1;
      FindClose(hFindFile);
      return;
    }
    BVar3 = FindNextFileA(hFindFile,&local_140);
  } while (BVar3 != 0);
  FindClose(hFindFile);
  return;
}


