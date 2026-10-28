void FUN_0053e680(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x18);
  *(undefined4 **)(param_1 + 400) = puVar1;
  *puVar1 = FUN_0053e980;
  puVar1[1] = FUN_0053ec30;
  puVar1[2] = FUN_0053e6d0;
  puVar1[3] = &LAB_0053e960;
  *(undefined1 *)(puVar1 + 4) = 0;
  *(undefined1 *)((int)puVar1 + 0x11) = 0;
  *(undefined1 *)(puVar1 + 5) = 1;
  return;
}


