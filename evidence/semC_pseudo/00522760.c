void FUN_00522760(uint *param_1,uint *param_2,uint *param_3)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  float fVar16;
  float fVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  float fVar25;
  float fVar26;
  uint uVar27;
  uint uVar28;
  
  fVar16 = (float)(*param_1 & _DAT_005cf2c0);
  fVar17 = (float)(param_1[1] & uRam005cf2c4);
  fVar25 = (float)(param_1[2] & uRam005cf2c8);
  fVar26 = (float)(param_1[3] & uRam005cf2cc);
  uVar13 = param_1[1] & uRam005cf2b4;
  uVar14 = param_1[2] & uRam005cf2b8;
  uVar15 = param_1[3] & uRam005cf2bc;
  fVar1 = fVar16 * _DAT_005cf2a0 + _DAT_005cf250;
  fVar4 = fVar17 * fRam005cf2a4 + fRam005cf254;
  fVar7 = fVar25 * fRam005cf2a8 + fRam005cf258;
  fVar10 = fVar26 * fRam005cf2ac + fRam005cf25c;
  fVar2 = fVar1 - _DAT_005cf250;
  fVar5 = fVar4 - fRam005cf254;
  fVar8 = fVar7 - fRam005cf258;
  fVar11 = fVar10 - fRam005cf25c;
  fVar16 = (((fVar16 - _DAT_005cf290 * fVar2) - _DAT_005cf280 * fVar2) - _DAT_005cf270 * fVar2) -
           _DAT_005cf260 * fVar2;
  fVar2 = (((fVar17 - fRam005cf294 * fVar5) - fRam005cf284 * fVar5) - fRam005cf274 * fVar5) -
          fRam005cf264 * fVar5;
  fVar17 = (((fVar25 - fRam005cf298 * fVar8) - fRam005cf288 * fVar8) - fRam005cf278 * fVar8) -
           fRam005cf268 * fVar8;
  fVar5 = (((fVar26 - fRam005cf29c * fVar11) - fRam005cf28c * fVar11) - fRam005cf27c * fVar11) -
          fRam005cf26c * fVar11;
  fVar25 = fVar16 * fVar16;
  fVar8 = fVar2 * fVar2;
  fVar26 = fVar17 * fVar17;
  fVar11 = fVar5 * fVar5;
  uVar18 = (uint)fVar1 & _DAT_005cf220;
  uVar19 = (uint)fVar4 & uRam005cf224;
  uVar21 = (uint)fVar7 & uRam005cf228;
  uVar23 = (uint)fVar10 & uRam005cf22c;
  uVar3 = uVar18 & _DAT_005cf210;
  uVar6 = uVar19 & uRam005cf214;
  uVar9 = uVar21 & uRam005cf218;
  uVar12 = uVar23 & uRam005cf21c;
  uVar20 = uVar19 - uVar6 & uRam005cf204;
  uVar22 = uVar21 - uVar9 & uRam005cf208;
  uVar24 = uVar23 - uVar12 & uRam005cf20c;
  uVar27 = uVar18 + uVar3 & _DAT_005cf200;
  uVar28 = uVar19 + uVar6 & uRam005cf204;
  uVar21 = uVar21 + uVar9 & uRam005cf208;
  uVar23 = uVar23 + uVar12 & uRam005cf20c;
  uVar19 = -(uint)((float)(uVar3 << 0x1e) != 0.0);
  uVar6 = -(uint)((float)(uVar6 << 0x1e) != 0.0);
  uVar9 = -(uint)((float)(uVar9 << 0x1e) != 0.0);
  uVar12 = -(uint)((float)(uVar12 << 0x1e) != 0.0);
  fVar16 = (((_DAT_005cf240 * fVar25 + _DAT_005cf1f0) * fVar25 + _DAT_005cf1d0) * fVar25 +
           _DAT_005cf1b0) * fVar16;
  fVar2 = (((fRam005cf244 * fVar8 + fRam005cf1f4) * fVar8 + fRam005cf1d4) * fVar8 + fRam005cf1b4) *
          fVar2;
  fVar17 = (((fRam005cf248 * fVar26 + fRam005cf1f8) * fVar26 + fRam005cf1d8) * fVar26 + fRam005cf1b8
           ) * fVar17;
  fVar5 = (((fRam005cf24c * fVar11 + fRam005cf1fc) * fVar11 + fRam005cf1dc) * fVar11 + fRam005cf1bc)
          * fVar5;
  fVar1 = (((_DAT_005cf230 * fVar25 + _DAT_005cf1e0) * fVar25 + _DAT_005cf1c0) * fVar25 +
          _DAT_005cf1a0) * fVar25 + _DAT_005cf190;
  fVar4 = (((fRam005cf234 * fVar8 + fRam005cf1e4) * fVar8 + fRam005cf1c4) * fVar8 + fRam005cf1a4) *
          fVar8 + fRam005cf194;
  fVar25 = (((fRam005cf238 * fVar26 + fRam005cf1e8) * fVar26 + fRam005cf1c8) * fVar26 + fRam005cf1a8
           ) * fVar26 + fRam005cf198;
  fVar7 = (((fRam005cf23c * fVar11 + fRam005cf1ec) * fVar11 + fRam005cf1cc) * fVar11 + fRam005cf1ac)
          * fVar11 + fRam005cf19c;
  *param_2 = (~uVar19 & (uint)fVar16 | uVar19 & (uint)fVar1) ^
             (uVar18 - uVar3 & _DAT_005cf200) << 0x1e ^ *param_1 & _DAT_005cf2b0;
  param_2[1] = (~uVar6 & (uint)fVar2 | uVar6 & (uint)fVar4) ^ uVar20 << 0x1e ^ uVar13;
  param_2[2] = (~uVar9 & (uint)fVar17 | uVar9 & (uint)fVar25) ^ uVar22 << 0x1e ^ uVar14;
  param_2[3] = (~uVar12 & (uint)fVar5 | uVar12 & (uint)fVar7) ^ uVar24 << 0x1e ^ uVar15;
  *param_3 = (uVar19 & (uint)fVar16 | ~uVar19 & (uint)fVar1) ^ uVar27 << 0x1e;
  param_3[1] = (uVar6 & (uint)fVar2 | ~uVar6 & (uint)fVar4) ^ uVar28 << 0x1e;
  param_3[2] = (uVar9 & (uint)fVar17 | ~uVar9 & (uint)fVar25) ^ uVar21 << 0x1e;
  param_3[3] = (uVar12 & (uint)fVar5 | ~uVar12 & (uint)fVar7) ^ uVar23 << 0x1e;
  return;
}


