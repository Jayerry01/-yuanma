void __thiscall FUN_00555950(int *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uStack_4;
  
  uStack_4 = (uint)param_1 & 0xffffff;
  iVar1 = param_1[1];
  iVar2 = *param_1;
  uVar4 = iVar1 - iVar2;
  uVar3 = param_3 + uVar4;
  if (uVar3 < uVar4) {
    FUN_00403870(iVar1,iVar1,iVar2 + uVar3,param_3,0);
    param_1[1] = param_1[1] + ((iVar2 + uVar3) - iVar1);
  }
  else {
    FUN_00552f50(iVar1,(iVar2 - iVar1) + uVar3,(int)&uStack_4 + 3);
  }
  puVar5 = (undefined4 *)(*param_1 + uVar4);
  for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar5 = *param_2;
    param_2 = param_2 + 1;
    puVar5 = puVar5 + 1;
  }
  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
    *(undefined1 *)puVar5 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  return;
}


