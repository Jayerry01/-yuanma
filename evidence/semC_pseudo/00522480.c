void FUN_00522480(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  uint uVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  
  fVar6 = (float)(*param_1 & _DAT_005cf0a0);
  fVar10 = (float)(param_1[1] & uRam005cf0a4);
  fVar14 = (float)(param_1[2] & uRam005cf0a8);
  fVar18 = (float)(param_1[3] & uRam005cf0ac);
  uVar22 = param_1[1] & uRam005cf094;
  uVar23 = param_1[2] & uRam005cf098;
  uVar24 = param_1[3] & uRam005cf09c;
  fVar7 = fVar6 * _DAT_005cf080 + _DAT_005cf030;
  fVar11 = fVar10 * fRam005cf084 + fRam005cf034;
  fVar15 = fVar14 * fRam005cf088 + fRam005cf038;
  fVar19 = fVar18 * fRam005cf08c + fRam005cf03c;
  fVar8 = fVar7 - _DAT_005cf030;
  fVar12 = fVar11 - fRam005cf034;
  fVar16 = fVar15 - fRam005cf038;
  fVar20 = fVar19 - fRam005cf03c;
  fVar6 = (((fVar6 - _DAT_005cf070 * fVar8) - _DAT_005cf060 * fVar8) - _DAT_005cf050 * fVar8) -
          _DAT_005cf040 * fVar8;
  fVar8 = (((fVar10 - fRam005cf074 * fVar12) - fRam005cf064 * fVar12) - fRam005cf054 * fVar12) -
          fRam005cf044 * fVar12;
  fVar10 = (((fVar14 - fRam005cf078 * fVar16) - fRam005cf068 * fVar16) - fRam005cf058 * fVar16) -
           fRam005cf048 * fVar16;
  fVar12 = (((fVar18 - fRam005cf07c * fVar20) - fRam005cf06c * fVar20) - fRam005cf05c * fVar20) -
           fRam005cf04c * fVar20;
  fVar14 = fVar6 * fVar6;
  fVar16 = fVar8 * fVar8;
  fVar18 = fVar10 * fVar10;
  fVar20 = fVar12 * fVar12;
  uVar25 = (uint)fVar7 & _DAT_005cf000;
  uVar26 = (uint)fVar11 & uRam005cf004;
  uVar27 = (uint)fVar15 & uRam005cf008;
  uVar28 = (uint)fVar19 & uRam005cf00c;
  uVar9 = uVar25 & _DAT_005ceff0;
  uVar13 = uVar26 & uRam005ceff4;
  uVar17 = uVar27 & uRam005ceff8;
  uVar21 = uVar28 & uRam005ceffc;
  uVar1 = uVar26 - uVar13 & _DAT_005cefe0;
  uVar2 = uVar27 - uVar17 & _DAT_005cefe0;
  uVar3 = uVar28 - uVar21 & _DAT_005cefe0;
  uVar4 = uVar25 + uVar9 & _DAT_005cefe0;
  uVar26 = uVar26 + uVar13 & _DAT_005cefe0;
  uVar27 = uVar27 + uVar17 & _DAT_005cefe0;
  uVar28 = uVar28 + uVar21 & _DAT_005cefe0;
  uVar5 = -(uint)((float)(uVar9 << 0x1e) != 0.0);
  uVar13 = -(uint)((float)(uVar13 << 0x1e) != 0.0);
  uVar17 = -(uint)((float)(uVar17 << 0x1e) != 0.0);
  uVar21 = -(uint)((float)(uVar21 << 0x1e) != 0.0);
  fVar6 = (((_DAT_005cf020 * fVar14 + _DAT_005cefd0) * fVar14 + _DAT_005cefb0) * fVar14 +
          _DAT_005cef90) * fVar6;
  fVar8 = (((fRam005cf024 * fVar16 + fRam005cefd4) * fVar16 + fRam005cefb4) * fVar16 + fRam005cef94)
          * fVar8;
  fVar10 = (((fRam005cf028 * fVar18 + fRam005cefd8) * fVar18 + fRam005cefb8) * fVar18 + fRam005cef98
           ) * fVar10;
  fVar12 = (((fRam005cf02c * fVar20 + fRam005cefdc) * fVar20 + fRam005cefbc) * fVar20 + fRam005cef9c
           ) * fVar12;
  fVar7 = (((_DAT_005cf010 * fVar14 + _DAT_005cefc0) * fVar14 + _DAT_005cefa0) * fVar14 +
          _DAT_005cef80) * fVar14 + _DAT_005cef70;
  fVar11 = (((fRam005cf014 * fVar16 + fRam005cefc4) * fVar16 + fRam005cefa4) * fVar16 + fRam005cef84
           ) * fVar16 + fRam005cef74;
  fVar14 = (((fRam005cf018 * fVar18 + fRam005cefc8) * fVar18 + fRam005cefa8) * fVar18 + fRam005cef88
           ) * fVar18 + fRam005cef78;
  fVar15 = (((fRam005cf01c * fVar20 + fRam005cefcc) * fVar20 + fRam005cefac) * fVar20 + fRam005cef8c
           ) * fVar20 + fRam005cef7c;
  *param_2 = (~uVar5 & (uint)fVar6 | uVar5 & (uint)fVar7) ^
             (uVar25 - uVar9 & _DAT_005cefe0) << 0x1e ^ *param_1 & _DAT_005cf090;
  param_2[1] = (~uVar13 & (uint)fVar8 | uVar13 & (uint)fVar11) ^ uVar1 << 0x1e ^ uVar22;
  param_2[2] = (~uVar17 & (uint)fVar10 | uVar17 & (uint)fVar14) ^ uVar2 << 0x1e ^ uVar23;
  param_2[3] = (~uVar21 & (uint)fVar12 | uVar21 & (uint)fVar15) ^ uVar3 << 0x1e ^ uVar24;
  *param_3 = (uVar5 & (uint)fVar6 | ~uVar5 & (uint)fVar7) ^ uVar4 << 0x1e;
  param_3[1] = (uVar13 & (uint)fVar8 | ~uVar13 & (uint)fVar11) ^ uVar26 << 0x1e;
  param_3[2] = (uVar17 & (uint)fVar10 | ~uVar17 & (uint)fVar14) ^ uVar27 << 0x1e;
  param_3[3] = (uVar21 & (uint)fVar12 | ~uVar21 & (uint)fVar15) ^ uVar28 << 0x1e;
  return;
}


