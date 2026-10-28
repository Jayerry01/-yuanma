uint __thiscall FUN_00480b00(int *param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  uint in_EAX;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_20 [26];
  ushort uStack_6;
  ushort local_4;
  
  if (param_1[6] != 0) {
    puVar1 = (undefined4 *)(*param_1 + param_2 * 0x18);
    in_EAX = 0;
    if ((*(int *)(*param_1 + 0x14 + param_2 * 0x18) != 0) && (in_EAX = 0, puVar1[4] != 0)) {
      FUN_0050a2d3(param_1[6],puVar1[3],0);
      in_EAX = FUN_0050a118(local_20,1,0x1e,param_1[6]);
      if (in_EAX == 0x1e) {
        param_2 = (uint)local_4 + (uint)uStack_6 + 0x1e + puVar1[4];
        pvVar2 = operator_new(param_2);
        in_EAX = 0;
        if (pvVar2 != (void *)0x0) {
          FUN_0050a2d3(param_1[6],0xffffffe2,1);
          in_EAX = FUN_0050a118(pvVar2,1,param_2,param_1[6]);
          if (in_EAX == param_2) {
            param_2 = 0;
            iVar3 = FUN_00484250(pvVar2,&param_2);
            in_EAX = FUN_00507850(pvVar2);
            if (iVar3 != 0) {
              if (param_2 == puVar1[5]) {
                uVar4 = (**(code **)*param_3)(*puVar1,iVar3,param_2);
                return uVar4;
              }
              in_EAX = thunk_FUN_005089fd(iVar3);
            }
          }
        }
      }
    }
  }
  return in_EAX & 0xffffff00;
}


