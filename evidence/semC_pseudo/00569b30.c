undefined4 __thiscall FUN_00569b30(int param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [64];
  
  if (*(int *)(param_1 + 0x120) == 0) {
    return 0;
  }
  iVar4 = FUN_00509f8f(param_2,&DAT_005ca380);
  if (iVar4 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x120) + 0x18) = 0;
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0x120);
  *(int *)(iVar2 + 0x10) =
       *(int *)(iVar2 + 0x10) + (*(int *)(iVar2 + 0x10) - *(int *)(iVar2 + 0xc) >> 3) * -8;
  bVar1 = *(byte *)(iVar4 + 0xc);
  while ((bVar1 & 0x10) == 0) {
    FUN_0050ab32(local_40,0x40,iVar4);
    FUN_0050ab32(local_40,0x40,iVar4);
    FUN_0050b600(iVar4,s__s__d_005d1280,local_40,&local_48);
    FUN_0050b600(iVar4,s__s__d_005d1280,local_40,&local_44);
    FUN_0050ab32(local_40,0x40,iVar4);
    iVar2 = *(int *)(param_1 + 0x120);
    puVar3 = *(undefined4 **)(iVar2 + 0x10);
    if (puVar3 == *(undefined4 **)(iVar2 + 0x14)) {
      FUN_0056b540(puVar3,&local_48);
    }
    else {
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = local_48;
        puVar3[1] = local_44;
      }
      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 8;
    }
    bVar1 = *(byte *)(iVar4 + 0xc);
  }
  FUN_00509e57(iVar4);
  iVar4 = *(int *)(param_1 + 0x120);
  *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x10) - *(int *)(iVar4 + 0xc) >> 3;
  FUN_005694e0(0,1);
  return 1;
}


