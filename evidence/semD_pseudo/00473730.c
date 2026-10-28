void __thiscall FUN_00473730(u_long *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  in_addr in;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  
  in.S_un = (_union_1226)htonl(*param_1);
  pcVar3 = inet_ntoa(in);
  uVar5 = 0xffffffff;
  pcVar9 = pcVar3;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  pcVar9 = (char *)*param_2;
  uVar6 = param_2[1] - (int)pcVar9;
  uVar4 = (int)(pcVar3 + (~uVar5 - 1)) - (int)pcVar3;
  if (uVar6 < uVar4) {
    pcVar8 = pcVar3;
    for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar9 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    }
    FUN_00403490(pcVar3 + (param_2[1] - *param_2),pcVar3 + (~uVar5 - 1));
  }
  else {
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar9 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pcVar9 = pcVar9 + 1;
    }
    iVar2 = param_2[1];
    iVar7 = *param_2 + uVar4;
    if (iVar7 != iVar2) {
      FUN_005092c0(iVar7,iVar2,1);
      param_2[1] = param_2[1] + (iVar7 - iVar2);
      return;
    }
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
