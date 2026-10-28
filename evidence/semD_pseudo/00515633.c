byte * FUN_00515633(byte *param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  
  if (DAT_007f1b3c == 0) {
    param_1 = (byte *)FUN_00510d90(param_1,param_2);
  }
  else {
    FUN_0050dd18(0x19);
    while( true ) {
      bVar1 = *param_1;
      uVar2 = (uint)bVar1;
      if (bVar1 == 0) break;
      if ((*(byte *)((int)&DAT_007f1c40 + uVar2 + 1) & 4) == 0) {
        pbVar3 = param_1;
        if (param_2 == uVar2) break;
      }
      else {
        pbVar3 = param_1 + 1;
        if (param_1[1] == 0) {
          FUN_0050dd79(0x19);
          return (byte *)0x0;
        }
        if (param_2 == CONCAT11(bVar1,param_1[1])) {
          FUN_0050dd79(0x19);
          return param_1;
        }
      }
      param_1 = pbVar3 + 1;
    }
    FUN_0050dd79(0x19);
    param_1 = (byte *)(~-(uint)(param_2 != uVar2) & (uint)param_1);
  }
  return param_1;
}


