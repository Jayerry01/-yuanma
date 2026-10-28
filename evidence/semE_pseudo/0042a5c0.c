void FUN_0042a5c0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(DAT_005d5a0c + 0x6cc);
  do {
    if (iVar1 == 0) {
      return;
    }
    if (*(int *)(iVar1 + 0x44) != 0) {
      iVar3 = *(int *)(iVar1 + 8);
      iVar4 = *(int *)(iVar1 + 0xc);
      for (iVar2 = *(int *)(iVar1 + 0x4c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4c)) {
        if (*(int *)(iVar2 + 0x44) == 0) {
          iVar3 = iVar3 + *(int *)(iVar2 + 0x18);
          iVar4 = iVar4 + *(int *)(iVar2 + 0x1c);
          break;
        }
        iVar3 = iVar3 + *(int *)(iVar2 + 8);
        iVar4 = iVar4 + *(int *)(iVar2 + 0xc);
      }
      *(int *)(iVar1 + 0x18) = iVar3;
      *(int *)(iVar1 + 0x1c) = iVar4;
      *(undefined4 *)(iVar1 + 0x44) = 0;
    }
    iVar1 = *(int *)(iVar1 + 0x5c);
  } while( true );
}


