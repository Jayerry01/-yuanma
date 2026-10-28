void FUN_00433880(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_4;
  
  if (DAT_007eabe0 == 8) {
    param_6 = param_6 + param_4;
    if (param_4 < param_6) {
      local_4 = 0;
      do {
        if ((-1 < param_4) && (param_4 < DAT_005d9b84)) {
          iVar2 = 0;
          iVar3 = DAT_005d9b7c * param_4;
          iVar1 = param_3;
          do {
            uVar4 = 7;
            do {
              if (param_5 + param_3 <= iVar1) break;
              if (((-1 < iVar1) && (iVar1 < DAT_005d9b80)) &&
                 ((*(byte *)(param_2 + local_4 + iVar2) & (byte)(1 << ((byte)uVar4 & 0x1f))) != 0))
              {
                *(undefined1 *)(iVar1 + iVar3 + param_1) = (undefined1)param_7;
              }
              uVar4 = uVar4 - 1;
              iVar1 = iVar1 + 1;
            } while (uVar4 < 0x80000000);
            iVar2 = iVar2 + 1;
          } while (iVar2 < 4);
        }
        param_4 = param_4 + 1;
        local_4 = local_4 + 4;
        if (param_6 <= param_4) {
          return;
        }
      } while( true );
    }
  }
  else if (DAT_007eabe0 == 0x10) {
    param_6 = param_6 + param_4;
    if (param_4 < param_6) {
      local_4 = 0;
      do {
        if ((-1 < param_4) && (param_4 < DAT_005d9b84)) {
          iVar2 = 0;
          iVar3 = DAT_005d9b7c * param_4;
          iVar1 = param_3;
          do {
            uVar4 = 7;
            do {
              if (param_5 + param_3 <= iVar1) break;
              if (((-1 < iVar1) && (iVar1 < DAT_005d9b80)) &&
                 ((*(byte *)(param_2 + local_4 + iVar2) & (byte)(1 << ((byte)uVar4 & 0x1f))) != 0))
              {
                *(undefined2 *)(iVar3 + param_1 + iVar1 * 2) = (undefined2)param_7;
              }
              uVar4 = uVar4 - 1;
              iVar1 = iVar1 + 1;
            } while (uVar4 < 0x80000000);
            iVar2 = iVar2 + 1;
          } while (iVar2 < 4);
        }
        param_4 = param_4 + 1;
        local_4 = local_4 + 4;
        if (param_6 <= param_4) {
          return;
        }
      } while( true );
    }
  }
  else {
    param_6 = param_6 + param_4;
    if (param_4 < param_6) {
      local_4 = 0;
      do {
        if ((-1 < param_4) && (param_4 < DAT_005d9b84)) {
          iVar2 = 0;
          iVar3 = DAT_005d9b7c * param_4;
          iVar1 = param_3;
          do {
            uVar4 = 7;
            do {
              if (param_5 + param_3 <= iVar1) break;
              if (((-1 < iVar1) && (iVar1 < DAT_005d9b80)) &&
                 ((*(byte *)(param_2 + local_4 + iVar2) & (byte)(1 << ((byte)uVar4 & 0x1f))) != 0))
              {
                *(undefined4 *)(iVar3 + param_1 + iVar1 * 4) = param_7;
              }
              uVar4 = uVar4 - 1;
              iVar1 = iVar1 + 1;
            } while (uVar4 < 0x80000000);
            iVar2 = iVar2 + 1;
          } while (iVar2 < 4);
        }
        param_4 = param_4 + 1;
        local_4 = local_4 + 4;
      } while (param_4 < param_6);
    }
  }
  return;
}


