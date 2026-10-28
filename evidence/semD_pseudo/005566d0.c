undefined4 FUN_005566d0(undefined4 param_1,int param_2)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  undefined1 local_20 [32];
  
  FUN_0050b600(param_1,s__s__s_005d12a8,local_20,param_2);
  FUN_00571c70(param_1,1);
  FUN_0050b600(param_1,s__s__s_005d12a8,local_20,param_2 + 0x10);
  FUN_0050b600(param_1,s__s__f__f__f_005d1298,local_20,(undefined4 *)(param_2 + 0x3c),param_2 + 0x40
               ,param_2 + 0x44);
  *(undefined4 *)(param_2 + 0x31c) = *(undefined4 *)(param_2 + 0x3c);
  *(undefined4 *)(param_2 + 800) = *(undefined4 *)(param_2 + 0x40);
  *(undefined4 *)(param_2 + 0x324) = *(undefined4 *)(param_2 + 0x44);
  FUN_0050b600(param_1,s__s__f__f__f__f_005d1288,local_20,param_2 + 0x30c,param_2 + 0x310,
               param_2 + 0x314,param_2 + 0x318);
  piVar1 = (int *)(param_2 + 0x34);
  FUN_0050b600(param_1,s__s__d_005d1280,local_20,piVar1);
  pvVar2 = operator_new(*piVar1 << 2);
  *(void **)(param_2 + 0x38) = pvVar2;
  iVar3 = 0;
  if (0 < *piVar1) {
    do {
      iVar3 = iVar3 + 1;
      *(undefined4 *)(*(int *)(param_2 + 0x38) + -4 + iVar3 * 4) = 0;
    } while (iVar3 < *piVar1);
  }
  FUN_00571c70(param_1,1);
  return 1;
}


