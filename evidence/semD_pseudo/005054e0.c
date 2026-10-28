int FUN_005054e0(undefined1 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = FUN_005055d0();
  puVar2 = (undefined1 *)(iVar1 * 0x40 + DAT_0066756c);
  *(undefined4 *)(puVar2 + 8) = 0;
  *(undefined4 *)(puVar2 + 4) = 0xffffffff;
  *puVar2 = 1;
  puVar2[1] = param_1;
  if ((DAT_00667578 & 1) == 0) {
    DAT_00667578 = DAT_00667578 | 1;
    DAT_006675a4 = 0;
    DAT_006675a8 = 0;
    DAT_006675ac = 0;
    FUN_005089bc(&DAT_00505650);
  }
  *(undefined4 *)(puVar2 + 0x24) = DAT_006675a4;
  *(undefined4 *)(puVar2 + 0x28) = DAT_006675a8;
  *(undefined4 *)(puVar2 + 0x2c) = DAT_006675ac;
  *(undefined4 *)(puVar2 + 0x18) = DAT_006675a4;
  *(undefined4 *)(puVar2 + 0x1c) = DAT_006675a8;
  *(undefined4 *)(puVar2 + 0x20) = DAT_006675ac;
  *(undefined4 *)(puVar2 + 0xc) = DAT_006675a4;
  *(undefined4 *)(puVar2 + 0x10) = DAT_006675a8;
  *(undefined4 *)(puVar2 + 0x14) = DAT_006675ac;
  *(undefined4 *)(puVar2 + 0x34) = 0x3f800000;
  *(undefined4 *)(puVar2 + 0x30) = 0x3f800000;
  *(undefined4 *)(puVar2 + 0x38) = DAT_00667594;
  *(undefined4 *)(puVar2 + 0x3c) = DAT_006675d8;
  return iVar1 + 1;
}


