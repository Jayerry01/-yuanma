undefined4 FUN_00484730(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_490;
  undefined4 local_48c;
  undefined4 local_488;
  undefined4 local_484;
  undefined4 local_480 [144];
  undefined4 local_240 [112];
  undefined4 local_80 [24];
  undefined4 local_20 [8];
  
  puVar2 = local_480;
  for (iVar1 = 0x90; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 8;
    puVar2 = puVar2 + 1;
  }
  puVar2 = local_240;
  for (iVar1 = 0x70; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 9;
    puVar2 = puVar2 + 1;
  }
  local_484 = 7;
  puVar2 = local_80;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 7;
    puVar2 = puVar2 + 1;
  }
  local_48c = 5;
  puVar2 = local_20;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 8;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_00484860(local_480,0x120,0x101,&DAT_005c8aa0,&DAT_005c8b20,&local_490,&local_484);
  if (iVar1 != 0) {
    return 1;
  }
  puVar2 = local_480;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 5;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_00484860(local_480,0x1e,0,&DAT_005c8ba0,&DAT_005c8c18,&local_488,&local_48c);
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = FUN_00484cb0(local_490,local_488,local_484,local_48c);
  if (iVar1 != 0) {
    return 1;
  }
  FUN_00484c90(local_490);
  FUN_00484c90(local_488);
  return 0;
}



undefined4