void FUN_0053c630(int *param_1,char *param_2,uint param_3,int param_4)

{
  char cVar1;
  int iVar2;
  
  param_4 = param_3 + param_4;
  if ((((param_3 < 0xe) || (*param_2 != 'J')) || (param_2[1] != 'F')) ||
     (((param_2[2] != 'I' || (param_2[3] != 'F')) || (param_2[4] != '\0')))) {
    if (((5 < param_3) && (*param_2 == 'J')) &&
       ((param_2[1] == 'F' && (((param_2[2] == 'X' && (param_2[3] == 'X')) && (param_2[4] == '\0')))
        ))) {
      cVar1 = param_2[5];
      if (cVar1 == '\x10') {
        *(undefined4 *)(*param_1 + 0x14) = 0x6c;
        *(int *)(*param_1 + 0x18) = param_4;
        (**(code **)(*param_1 + 4))(param_1,1);
        return;
      }
      if (cVar1 != '\x11') {
        if (cVar1 != '\x13') {
          *(undefined4 *)(*param_1 + 0x14) = 0x59;
          *(uint *)(*param_1 + 0x18) = (uint)(byte)param_2[5];
          *(int *)(*param_1 + 0x1c) = param_4;
          (**(code **)(*param_1 + 4))();
          return;
        }
        *(undefined4 *)(*param_1 + 0x14) = 0x6e;
        *(int *)(*param_1 + 0x18) = param_4;
        (**(code **)(*param_1 + 4))(param_1);
        return;
      }
      *(undefined4 *)(*param_1 + 0x14) = 0x6d;
      *(int *)(*param_1 + 0x18) = param_4;
      (**(code **)(*param_1 + 4))(param_1);
      return;
    }
    *(undefined4 *)(*param_1 + 0x14) = 0x4d;
    *(int *)(*param_1 + 0x18) = param_4;
    (**(code **)(*param_1 + 4))(param_1,1);
  }
  else {
    *(undefined1 *)(param_1 + 0x40) = 1;
    *(char *)((int)param_1 + 0x101) = param_2[5];
    *(char *)((int)param_1 + 0x102) = param_2[6];
    *(char *)((int)param_1 + 0x103) = param_2[7];
    *(ushort *)(param_1 + 0x41) = (ushort)(byte)param_2[8] * 0x100 + (ushort)(byte)param_2[9];
    *(ushort *)((int)param_1 + 0x106) =
         (ushort)(byte)param_2[10] * 0x100 + (ushort)(byte)param_2[0xb];
    if (*(char *)((int)param_1 + 0x101) != '\x01') {
      *(undefined4 *)(*param_1 + 0x14) = 0x77;
      *(uint *)(*param_1 + 0x18) = (uint)*(byte *)((int)param_1 + 0x101);
      *(uint *)(*param_1 + 0x1c) = (uint)*(byte *)((int)param_1 + 0x102);
      (**(code **)(*param_1 + 4))(param_1,0xffffffff);
    }
    iVar2 = *param_1;
    *(uint *)(iVar2 + 0x18) = (uint)*(byte *)((int)param_1 + 0x101);
    *(uint *)(iVar2 + 0x1c) = (uint)*(byte *)((int)param_1 + 0x102);
    *(uint *)(iVar2 + 0x20) = (uint)*(ushort *)(param_1 + 0x41);
    *(uint *)(iVar2 + 0x24) = (uint)*(ushort *)((int)param_1 + 0x106);
    *(uint *)(iVar2 + 0x28) = (uint)*(byte *)((int)param_1 + 0x103);
    *(undefined4 *)(*param_1 + 0x14) = 0x57;
    (**(code **)(*param_1 + 4))(param_1,1);
    if (param_2[0xc] != '\0' || param_2[0xd] != '\0') {
      *(undefined4 *)(*param_1 + 0x14) = 0x5a;
      *(uint *)(*param_1 + 0x18) = (uint)(byte)param_2[0xc];
      *(uint *)(*param_1 + 0x1c) = (uint)(byte)param_2[0xd];
      (**(code **)(*param_1 + 4))(param_1,1);
    }
    if (param_4 + -0xe != (uint)(byte)param_2[0xc] * (uint)(byte)param_2[0xd] * 3) {
      *(undefined4 *)(*param_1 + 0x14) = 0x58;
      *(int *)(*param_1 + 0x18) = param_4 + -0xe;
      (**(code **)(*param_1 + 4))(param_1,1);
      return;
    }
  }
  return;
}


