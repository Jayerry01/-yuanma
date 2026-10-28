void __fastcall FUN_0055ab70(int param_1)

{
  float10 fVar1;
  undefined1 auStack_40 [64];
  
  if (*(float *)(param_1 + 0x166c) < 0.3) {
    if (0.1 <= *(float *)(param_1 + 0x166c)) {
      FUN_00475590(1,1);
      FUN_00477200();
      FUN_004781d0(0x422c0000,0x41e80000,0xbf800000,0);
      FUN_004745d0(auStack_40);
      FUN_00479f80(*(undefined4 *)(param_1 + 0x1480));
      FUN_0047c2e0(0);
      FUN_00475590(1,0);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x166c) = 0;
  }
  fVar1 = (float10)FUN_004748b0();
  *(float *)(param_1 + 0x166c) = (float)(fVar1 + (float10)*(float *)(param_1 + 0x166c));
  return;
}


