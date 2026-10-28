int FUN_005364d0(int param_1,int param_2,uint param_3,uint param_4,uint param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  DAT_007dc780 = *(uint *)(param_1 + 0x10) / (uint)*(byte *)(param_1 + 0xd);
  DAT_007dc810 = *(uint *)(param_2 + 0x10) / (uint)*(byte *)(param_2 + 0xd);
  DAT_007dc79c = *(uint *)(param_1 + 0x1c) / (uint)*(byte *)(param_1 + 0xd);
  DAT_007dc818 = *(uint *)(param_2 + 0x1c) / (uint)*(byte *)(param_2 + 0xd);
  cVar1 = *(char *)(param_1 + 0xd);
  if (cVar1 == '\x01') {
    DAT_007dc798 = 0;
    if (param_5 != 0) {
      do {
        uVar5 = DAT_007dc798;
        DAT_007dc808 = DAT_007dc798 * DAT_007dc818;
        iVar2 = __ftol();
        DAT_007dc80c = iVar2 * DAT_007dc79c;
        DAT_007dc794 = 0;
        if (param_4 != 0) {
          do {
            uVar4 = DAT_007dc794;
            DAT_007dc800 = DAT_007dc794 * DAT_007dc810;
            iVar2 = __ftol();
            DAT_007dc804 = iVar2 * DAT_007dc780;
            DAT_007dc790 = 0;
            if (param_3 != 0) {
              do {
                uVar5 = DAT_007dc790;
                iVar2 = *(byte *)(param_2 + 0xc) * DAT_007dc790;
                DAT_007dc7f8 = iVar2;
                iVar3 = __ftol();
                DAT_007dc7fc = iVar3 * (uint)*(byte *)(param_1 + 0xc);
                DAT_007dc820 = 0;
                if (*(char *)(param_2 + 0xc) != '\0') {
                  do {
                    *(undefined1 *)
                     (DAT_007dc808 + *(int *)(param_2 + 0x14) + DAT_007dc820 + iVar2 + DAT_007dc800)
                         = *(undefined1 *)
                            (DAT_007dc7fc + DAT_007dc820 + DAT_007dc804 + DAT_007dc80c +
                            *(int *)(param_1 + 0x14));
                    DAT_007dc820 = DAT_007dc820 + 1;
                    uVar4 = DAT_007dc794;
                    uVar5 = DAT_007dc790;
                    iVar2 = DAT_007dc7f8;
                  } while (DAT_007dc820 < *(byte *)(param_2 + 0xc));
                }
                DAT_007dc790 = uVar5 + 1;
                uVar5 = DAT_007dc798;
              } while (DAT_007dc790 < param_3);
            }
            DAT_007dc794 = uVar4 + 1;
          } while (DAT_007dc794 < param_4);
        }
        DAT_007dc798 = uVar5 + 1;
      } while (DAT_007dc798 < param_5);
    }
  }
  else if (cVar1 == '\x02') {
    DAT_007dc81c = *(int *)(param_1 + 0x14);
    DAT_007dc7a0 = *(int *)(param_2 + 0x14);
    DAT_007dc798 = 0;
    if (param_5 != 0) {
      do {
        uVar5 = DAT_007dc798;
        DAT_007dc808 = DAT_007dc798 * DAT_007dc818;
        iVar2 = __ftol();
        DAT_007dc80c = iVar2 * DAT_007dc79c;
        DAT_007dc794 = 0;
        if (param_4 != 0) {
          do {
            uVar4 = DAT_007dc794;
            DAT_007dc800 = DAT_007dc794 * DAT_007dc810;
            iVar2 = __ftol();
            DAT_007dc804 = iVar2 * DAT_007dc780;
            DAT_007dc790 = 0;
            if (param_3 != 0) {
              do {
                uVar5 = DAT_007dc790;
                iVar2 = *(byte *)(param_2 + 0xc) * DAT_007dc790;
                DAT_007dc7f8 = iVar2;
                iVar3 = __ftol();
                DAT_007dc7fc = iVar3 * (uint)*(byte *)(param_1 + 0xc);
                DAT_007dc820 = 0;
                if (*(char *)(param_2 + 0xc) != '\0') {
                  do {
                    *(undefined2 *)
                     (DAT_007dc7a0 + (DAT_007dc820 + iVar2 + DAT_007dc800 + DAT_007dc808) * 2) =
                         *(undefined2 *)
                          (DAT_007dc81c +
                          (DAT_007dc7fc + DAT_007dc820 + DAT_007dc804 + DAT_007dc80c) * 2);
                    DAT_007dc820 = DAT_007dc820 + 1;
                    uVar4 = DAT_007dc794;
                    uVar5 = DAT_007dc790;
                    iVar2 = DAT_007dc7f8;
                  } while (DAT_007dc820 < *(byte *)(param_2 + 0xc));
                }
                DAT_007dc790 = uVar5 + 1;
                uVar5 = DAT_007dc798;
              } while (DAT_007dc790 < param_3);
            }
            DAT_007dc794 = uVar4 + 1;
          } while (DAT_007dc794 < param_4);
        }
        DAT_007dc798 = uVar5 + 1;
      } while (DAT_007dc798 < param_5);
      return param_2;
    }
  }
  else if (cVar1 == '\x04') {
    DAT_007dc7a4 = *(int *)(param_1 + 0x14);
    DAT_007dc7c0 = *(int *)(param_2 + 0x14);
    DAT_007dc798 = 0;
    if (param_5 != 0) {
      do {
        uVar5 = DAT_007dc798;
        DAT_007dc808 = DAT_007dc798 * DAT_007dc818;
        iVar2 = __ftol();
        DAT_007dc80c = iVar2 * DAT_007dc79c;
        DAT_007dc794 = 0;
        if (param_4 != 0) {
          do {
            uVar4 = DAT_007dc794;
            DAT_007dc800 = DAT_007dc794 * DAT_007dc810;
            iVar2 = __ftol();
            DAT_007dc804 = iVar2 * DAT_007dc780;
            DAT_007dc790 = 0;
            if (param_3 != 0) {
              do {
                uVar5 = DAT_007dc790;
                iVar2 = *(byte *)(param_2 + 0xc) * DAT_007dc790;
                DAT_007dc7f8 = iVar2;
                iVar3 = __ftol();
                DAT_007dc7fc = iVar3 * (uint)*(byte *)(param_1 + 0xc);
                DAT_007dc820 = 0;
                if (*(char *)(param_2 + 0xc) != '\0') {
                  do {
                    *(undefined4 *)
                     (DAT_007dc7c0 + (DAT_007dc820 + iVar2 + DAT_007dc800 + DAT_007dc808) * 4) =
                         *(undefined4 *)
                          (DAT_007dc7a4 +
                          (DAT_007dc820 + DAT_007dc7fc + DAT_007dc804 + DAT_007dc80c) * 4);
                    DAT_007dc820 = DAT_007dc820 + 1;
                    uVar4 = DAT_007dc794;
                    uVar5 = DAT_007dc790;
                    iVar2 = DAT_007dc7f8;
                  } while (DAT_007dc820 < *(byte *)(param_2 + 0xc));
                }
                DAT_007dc790 = uVar5 + 1;
                uVar5 = DAT_007dc798;
              } while (DAT_007dc790 < param_3);
            }
            DAT_007dc794 = uVar4 + 1;
          } while (DAT_007dc794 < param_4);
        }
        DAT_007dc798 = uVar5 + 1;
      } while (DAT_007dc798 < param_5);
      return param_2;
    }
  }
  return param_2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
