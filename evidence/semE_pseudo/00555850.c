void FUN_00555850(undefined4 *param_1,int param_2,uint param_3)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  if (param_3 != 0) {
    puVar1 = (undefined2 *)(param_2 + 2);
    do {
      puVar2 = puVar1 + 2;
      *param_1 = CONCAT31(CONCAT21(*puVar1,*(undefined1 *)((int)puVar1 + -1)),
                          *(undefined1 *)(puVar1 + -1));
      puVar1 = puVar2;
      param_1 = param_1 + 1;
    } while ((uint)((-2 - param_2) + (int)puVar2) < param_3);
  }
  return;
}


