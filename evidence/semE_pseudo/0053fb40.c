void FUN_0053fb40(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x1c);
  *(undefined4 **)(param_1 + 0x180) = puVar1;
  *puVar1 = FUN_0053fde0;
  puVar1[1] = &LAB_0053ff40;
  *(undefined1 *)(puVar1 + 2) = 0;
  FUN_0053fb80(param_1);
  return;
}


