
void __thiscall FUN_004a96c0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int *piStack_10;
  undefined1 auStack_c [4];
  undefined1 auStack_8 [4];
  int *piStack_4;
  
  FUN_004db820(auStack_c);
  FUN_004e8720(auStack_8);
  FUN_0049a680(auStack_c);
  FUN_0049a680(auStack_8);
  for (; (piStack_10 != piStack_4 && (piStack_10[2] != param_2)); piStack_10 = (int *)*piStack_10) {
  }
  if (piStack_10 != *(int **)(param_1 + 4)) {
    FUN_004e8720(&piStack_10);
    puVar1 = (undefined4 *)FUN_004a97b0(&param_2);
    *puVar1 = piStack_10;
    puVar1[1] = piStack_10[1];
    *(undefined4 **)piStack_10[1] = puVar1;
    piStack_10[1] = (int)puVar1;
  }
  return;
}

