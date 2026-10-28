void __thiscall FUN_00554cd0(undefined2 *param_1,int param_2)

{
  ushort uVar1;
  void *pvVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  *param_1 = *(undefined2 *)(param_2 + 6);
  uVar1 = FUN_00553870();
  param_1[8] = uVar1;
  pvVar2 = operator_new((uint)uVar1);
  uVar1 = param_1[8];
  *(void **)(param_1 + 10) = pvVar2;
  puVar3 = (undefined4 *)FUN_00553880();
  puVar5 = *(undefined4 **)(param_1 + 10);
  for (uVar4 = (uint)(uVar1 >> 2); uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  for (uVar4 = uVar1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar5 = *(undefined1 *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  return;
}


