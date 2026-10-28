void __thiscall FUN_0050791f(int param_1,int param_2)

{
  if ((*(int *)(param_1 + 0x1c) != 0) && (*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0)) {
    (**(code **)**(undefined4 **)(param_1 + 4))(1);
  }
  *(int *)(param_1 + 4) = param_2;
  if (param_2 == 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;
  }
  else {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffffb;
  }
  return;
}


