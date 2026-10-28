void __thiscall FUN_004faf50(int param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(param_1 + 0x10);
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  bVar2 = *param_2;
  while (bVar2 != 0) {
    pbVar1 = (byte *)(((int)(char)bVar2 >> 3) + 0x10 + param_1);
    param_2 = param_2 + 1;
    *pbVar1 = *pbVar1 | '\x01' << (bVar2 & 7);
    bVar2 = *param_2;
  }
  return;
}


