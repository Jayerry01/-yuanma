undefined1 FUN_0053b910(int param_1)

{
  char cVar1;
  
  if ((((*(short *)(param_1 + 0xc) != 0) && (*(short *)(param_1 + 0xe) != 0)) &&
      (((cVar1 = *(char *)(param_1 + 0x10), cVar1 == '\b' ||
        (((cVar1 == '\x0f' || (cVar1 == '\x10')) || (cVar1 == '\x18')))) || (cVar1 == ' ')))) &&
     ((*(byte *)(param_1 + 0x11) & 0x10) == 0)) {
    if (cVar1 == '\x0f') {
      *(undefined1 *)(param_1 + 0x10) = 0x10;
    }
    return 1;
  }
  return 0;
}


