void FUN_00421d00(HDC param_1,uint param_2,LPCSTR param_3,undefined1 param_4)

{
  char cVar1;
  LPCSTR lpString;
  int iVar2;
  uint uVar3;
  int unaff_EBX;
  LPCSTR pCVar4;
  int unaff_retaddr;
  
  lpString = param_3;
  iVar2 = -1;
  pCVar4 = param_3;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pCVar4;
    pCVar4 = pCVar4 + 1;
  } while (cVar1 != '\0');
  if (iVar2 != -2) {
    iVar2 = FUN_00410a60();
    if (iVar2 != 0) {
      (**(code **)(**(int **)(iVar2 + 0x6f4) + 0x44))(*(int **)(iVar2 + 0x6f4),&param_3);
      SetBkMode(param_1,1);
      SetTextColor(param_1,(uint)CONCAT11(param_4,param_3._0_1_) << 8 | param_2 & 0xff);
      uVar3 = 0xffffffff;
      pCVar4 = lpString;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pCVar4;
        pCVar4 = pCVar4 + 1;
      } while (cVar1 != '\0');
      TextOutA(param_1,unaff_EBX,unaff_retaddr,lpString,~uVar3 - 1);
      (**(code **)(**(int **)(iVar2 + 0x6f4) + 0x68))(*(int **)(iVar2 + 0x6f4),param_1);
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
