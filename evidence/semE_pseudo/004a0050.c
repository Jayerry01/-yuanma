int __fastcall FUN_004a0050(int param_1)

{
  byte *pbVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  bVar2 = false;
  do {
    pbVar1 = *(byte **)(param_1 + 8);
    if (*pbVar1 < 0x21) {
      bVar2 = true;
    }
    else if (bVar2) {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + iVar4;
      if ((*pbVar1 == 0x23) || (*pbVar1 == 0x3b)) {
        iVar3 = FUN_0049fff0(0);
        iVar4 = iVar4 + iVar3;
      }
      return iVar4;
    }
    iVar4 = iVar4 + 1;
    *(byte **)(param_1 + 8) = pbVar1 + 1;
  } while( true );
}


