void FUN_00407b50(undefined4 *param_1,int param_2,int param_3)

{
  if (param_2 == 0) {
    *param_1 = 0x3f800000;
    param_1[1] = 0;
  }
  else {
    if (param_2 != 1) {
      if (param_2 != 2) {
        if (param_2 == 3) {
          param_1[1] = 0;
          param_1[2] = 0;
          *param_1 = 0xbf800000;
        }
        else {
          if (param_2 == 4) {
            param_1[1] = 0xbf800000;
            param_1[2] = 0;
          }
          else {
            if (param_2 != 5) {
              return;
            }
            param_1[1] = 0;
            param_1[2] = 0xbf800000;
          }
          *param_1 = 0;
        }
        if (param_3 != 4) {
          return;
        }
        param_1[3] = 0x3f800000;
        return;
      }
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0x3f800000;
      goto LAB_00407b6b;
    }
    *param_1 = 0;
    param_1[1] = 0x3f800000;
  }
  param_1[2] = 0;
LAB_00407b6b:
  if (param_3 != 4) {
    return;
  }
  param_1[3] = 0x3f800000;
  return;
}


