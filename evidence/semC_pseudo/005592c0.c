void __thiscall FUN_005592c0(int *param_1,undefined4 param_2)

{
  char cVar1;
  float *pfVar2;
  float10 fVar3;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (((param_1[0x11] != 0) && (param_1[0x10] != 0)) && (param_1[0x12] != 0)) {
    if ((param_1[0xca] != 0) && (cVar1 = FUN_00474990(param_1 + 0x7a), cVar1 != '\0')) {
      param_1[0x1b] = 1;
      if ((param_1[0xcc] != 0) && (param_1[0x1a] == 0)) {
        pfVar2 = (float *)FUN_00476090(3);
        local_24 = *pfVar2;
        local_20 = pfVar2[1];
        local_1c = pfVar2[2];
        FUN_00477d30(3,&local_30);
        local_18 = local_24 - local_30;
        local_14 = local_20 - local_2c;
        local_10 = local_1c - local_28;
        local_c = local_18;
        local_8 = local_14;
        local_4 = local_10;
        fVar3 = (float10)FUN_0047ecf0();
        if (fVar3 < (float10)250.0) {
          local_28 = local_28 + 40.0;
          FUN_005795b0(&local_30);
          FUN_00579a90();
        }
      }
      if (param_1[0xd0] != 0) {
        FUN_00475590(0x11,1);
      }
      if (param_1[0xd1] != 0) {
        FUN_005590b0();
      }
      if (param_1[0xcf] != 0) {
        FUN_00558f90(param_2);
      }
      if (param_1[0xce] != 0) {
        (**(code **)(*param_1 + 4))();
      }
      if (param_1[0xcd] != 0) {
        FUN_00475590(4,0);
        FUN_00558f50();
        FUN_00475590(4,1);
      }
      if (param_1[0xd0] == 0) {
        return;
      }
      FUN_00475590(0x11,2);
      return;
    }
    param_1[0x1b] = 0;
  }
  return;
}


