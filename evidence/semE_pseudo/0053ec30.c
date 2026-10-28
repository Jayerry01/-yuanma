void FUN_0053ec30(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[100];
  *puVar1 = FUN_0053e980;
  *(undefined1 *)(puVar1 + 4) = 0;
  *(undefined1 *)((int)puVar1 + 0x11) = 0;
  *(undefined1 *)(puVar1 + 5) = 1;
  (**(code **)(*param_1 + 0x10))(param_1);
  (**(code **)param_1[0x65])(param_1);
  param_1[0x23] = 0;
  return;
}


