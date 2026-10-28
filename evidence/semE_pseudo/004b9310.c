void __fastcall FUN_004b9310(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_004049c0(0,1,1);
    FUN_00429f40(0,0);
    FUN_004a9570();
    FUN_0040e7c0();
    return;
  }
  return;
}



void __fastcall thunk_FUN_004a9530(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  piVar2 = (int *)**(int **)(param_1 + 4);
  if (piVar2 != *(int **)(param_1 + 4)) {
    do {
      if ((int *)piVar2[2] == (int *)0x0) {
        puVar1 = (undefined4 *)piVar2[1];
        puVar3 = (undefined4 *)*piVar2;
        *puVar1 = puVar3;
        puVar3[1] = puVar1;
        FUN_00402e90(piVar2,0xc);
      }
      else {
        (**(code **)(*(int *)piVar2[2] + 4))();
        puVar3 = (undefined4 *)*piVar2;
      }
      piVar2 = puVar3;
    } while (puVar3 != *(undefined4 **)(param_1 + 4));
  }
  return;
}


