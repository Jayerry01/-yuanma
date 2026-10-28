void __thiscall FUN_005536a0(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  cVar1 = *(char *)(param_2 + 4);
  if (cVar1 == '\x03') {
    if (param_1[2] == 1) {
      FUN_00553960(&param_2,4);
      param_1[1] = param_2;
      FUN_00553960(&param_2,4);
      FUN_005561e0(param_2);
      param_1[2] = 2;
      (**(code **)(*param_1 + 0x14))(param_1[1]);
    }
  }
  else {
    if (cVar1 == '\x04') {
      *(undefined1 *)(param_1 + 3) = 1;
      FUN_00553960(&param_2,4);
      param_1[4] = param_2;
      return;
    }
    if ((cVar1 == '\x7f') && (param_1[2] == 2)) {
      iVar2 = *param_1;
      uVar3 = FUN_00553890(*(undefined2 *)(param_2 + 0xc));
      (**(code **)(iVar2 + 0x10))(uVar3);
      return;
    }
  }
  return;
}


