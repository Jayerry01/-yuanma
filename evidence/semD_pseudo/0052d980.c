uint FUN_0052d980(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  bool bVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  int local_4;
  
  local_8 = 0x12;
  local_7 = 0xf6;
  local_6 = 0xf3;
  local_c = 0;
  local_b = 0;
  local_a = 0;
  bVar4 = true;
  if (DAT_0072329c == 0) {
    uVar5 = FUN_00530d00(0x506);
    return uVar5 & 0xffffff00;
  }
  uVar5 = FUN_0052c880(0x40,0x40,1,3,0x80e0,0x1401,0);
  if ((char)uVar5 != '\0') {
    *(undefined4 *)(DAT_0072329c + 0x28) = 0x601;
    local_4 = 8;
    puVar6 = *(undefined1 **)(DAT_0072329c + 0x14);
    do {
      bVar4 = !bVar4;
      if (bVar4) {
        puVar7 = &local_8;
      }
      else {
        puVar7 = &local_c;
      }
      iVar10 = 8;
      do {
        iVar9 = 8;
        do {
          uVar1 = *puVar7;
          uVar2 = puVar7[1];
          uVar3 = puVar7[2];
          iVar8 = 8;
          do {
            *puVar6 = uVar1;
            puVar6[1] = uVar2;
            puVar6[2] = uVar3;
            puVar6 = puVar6 + *(byte *)(DAT_0072329c + 0xc);
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          bVar4 = !bVar4;
          if (bVar4) {
            puVar7 = &local_8;
          }
          else {
            puVar7 = &local_c;
          }
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      local_4 = local_4 + -1;
    } while (local_4 != 0);
    return CONCAT31((int3)((uint)puVar6 >> 8),1);
  }
  return uVar5;
}


