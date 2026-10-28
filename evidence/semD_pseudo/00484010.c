void FUN_00484010(int param_1,int param_2,ushort *param_3,int param_4,byte *param_5,int param_6)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  ushort *puVar5;
  int iVar6;
  
  puVar5 = param_3;
  if (0 < param_2) {
    param_3 = (ushort *)param_2;
    do {
      iVar6 = param_1;
      if (0 < param_1) {
        do {
          pbVar1 = param_5 + 3;
          bVar4 = *param_5;
          pbVar2 = param_5 + 1;
          pbVar3 = param_5 + 2;
          param_5 = param_5 + 4;
          *puVar5 = (((ushort)(*pbVar1 >> 7) << 5 | (ushort)(bVar4 >> 3)) << 5 |
                    (ushort)(*pbVar2 >> 3)) << 5 | (ushort)(*pbVar3 >> 3);
          puVar5 = puVar5 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      puVar5 = (ushort *)((int)puVar5 + param_4 + param_1 * -2);
      param_5 = param_5 + param_6 + param_1 * -4;
      param_3 = (ushort *)((int)param_3 + -1);
    } while (param_3 != (ushort *)0x0);
  }
  return;
}


