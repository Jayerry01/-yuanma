undefined4 FUN_00435120(undefined4 param_1,uint param_2,undefined1 param_3,undefined1 param_4)

{
  int iVar1;
  int *piVar2;
  HDC unaff_ESI;
  
  piVar2 = (int *)thunk_FUN_0042a010(param_1);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  if ((undefined4 *)*piVar2 == (undefined4 *)0x0) {
    return 0;
  }
  iVar1 = **(int **)*piVar2;
  piVar2 = *(int **)(iVar1 + 0x34);
  (**(code **)(*piVar2 + 0x44))(piVar2,&param_1);
  SetBkMode(unaff_ESI,2);
  SetBkColor(unaff_ESI,(uint)CONCAT11(param_4,param_3) << 8 | param_2 & 0xff);
  piVar2 = *(int **)(iVar1 + 0x34);
  (**(code **)(*piVar2 + 0x68))(piVar2,unaff_ESI);
  return 1;
}


