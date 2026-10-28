void FUN_0041a9b0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 *puVar5;
  float fVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  uint uVar9;
  
  iVar4 = DAT_005d5a0c;
  if (DAT_005c4308 != 0) {
    if (param_2 != 0) {
      uVar7 = __ftol();
      uVar8 = __ftol();
      uVar9 = __ftol();
      FUN_0041a970(*(undefined4 *)(iVar4 + 0x760),0x1c,1);
      FUN_0041a970(*(undefined4 *)(DAT_005d5a0c + 0x760),0x22,
                   (uint)CONCAT11(uVar8,uVar7) << 8 | uVar9 & 0xff);
      if ((DAT_005c4324 == 0) || (DAT_005d5a50 == 0)) {
        if ((char)(&DAT_007e0f54)[DAT_005d5ac4 * 0x140] < '\0') {
          FUN_0041a950(*(undefined4 *)(DAT_005d5a0c + 0x760),4,3);
          FUN_0041a950(*(undefined4 *)(DAT_005d5a0c + 0x760),5,*(undefined4 *)(DAT_005d5a0c + 0x724)
                      );
          FUN_0041a950(*(undefined4 *)(DAT_005d5a0c + 0x760),6,*(undefined4 *)(DAT_005d5a0c + 0x728)
                      );
          FUN_0041a970(*(undefined4 *)(DAT_005d5a0c + 0x760),0x30,1);
        }
      }
      else if ((*(uint *)(&DAT_007e0f54 + DAT_005d5ac4 * 0x140) & 0x100) != 0) {
        if ((*(uint *)(&DAT_007e0f54 + DAT_005d5ac4 * 0x140) & 0x100000) == 0) {
          iVar4 = *(int *)(*(int *)(param_1 + 0x14) + 0x9c);
          fVar1 = *(float *)(iVar4 + 0x18);
          fVar6 = 1.0 / (*(float *)(iVar4 + 0x1c) - fVar1);
          fVar2 = *(float *)(DAT_005d5a0c + 0x724);
          fVar3 = *(float *)(DAT_005d5a0c + 0x728);
          FUN_0041a970(*(undefined4 *)(DAT_005d5a0c + 0x760),0x23,3);
          FUN_0041a970(*(undefined4 *)(DAT_005d5a0c + 0x760),0x24,(fVar2 - fVar1) * fVar6);
          FUN_0041a970(*(undefined4 *)(DAT_005d5a0c + 0x760),0x25,(fVar3 - fVar1) * fVar6);
        }
        else {
          FUN_0041a970(*(undefined4 *)(DAT_005d5a0c + 0x760),0x23,3);
          FUN_0041a970(*(undefined4 *)(DAT_005d5a0c + 0x760),0x24,
                       *(undefined4 *)(DAT_005d5a0c + 0x724));
          FUN_0041a970(*(undefined4 *)(DAT_005d5a0c + 0x760),0x25,
                       *(undefined4 *)(DAT_005d5a0c + 0x728));
        }
      }
      puVar5 = *(undefined4 **)(DAT_005d5a0c + 0x720);
      FUN_004155c0(param_1,*puVar5,puVar5[1],puVar5[2]);
      return;
    }
    FUN_0041a970(*(undefined4 *)(DAT_005d5a0c + 0x760),0x1c,0);
    FUN_0041a970(*(undefined4 *)(DAT_005d5a0c + 0x760),0x30,0);
    FUN_004155c0(param_1,*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24),
                 *(undefined4 *)(param_1 + 0x28));
  }
  return;
}


