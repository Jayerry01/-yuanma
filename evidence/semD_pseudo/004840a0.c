void FUN_004840a0(int param_1,int param_2,ushort *param_3,int param_4,byte *param_5,int param_6)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  ushort *puVar4;
  int iVar5;
  
  puVar4 = param_3;
  if (0 < param_2) {
    param_3 = (ushort *)param_2;
    do {
      iVar5 = param_1;
      if (0 < param_1) {
        do {
          bVar3 = *param_5;
          pbVar1 = param_5 + 1;
          pbVar2 = param_5 + 2;
          param_5 = param_5 + 4;
          *puVar4 = ((ushort)(*pbVar1 >> 2) | (ushort)(bVar3 >> 3) << 6) << 5 |
                    (ushort)(*pbVar2 >> 3);
          puVar4 = puVar4 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      puVar4 = (ushort *)((int)puVar4 + param_4 + param_1 * -2);
      param_5 = param_5 + param_6 + param_1 * -4;
      param_3 = (ushort *)((int)param_3 + -1);
    } while (param_3 != (ushort *)0x0);
  }
  return;
}


