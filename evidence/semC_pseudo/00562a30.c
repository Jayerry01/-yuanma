void __fastcall FUN_00562a30(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  int local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  undefined1 local_98 [64];
  undefined1 local_58 [12];
  undefined1 local_4c [12];
  undefined4 local_40 [16];
  
  local_cc = 0;
  piVar4 = *(int **)(param_1 + 0x4b4);
  *(undefined4 *)(param_1 + 0x224) = 0;
  if (0 < *(int *)(param_1 + 0x4b0)) {
    do {
      if (((((char)piVar4[2] != '\0') && (*(char *)((int)piVar4 + 9) != '\0')) && (piVar4[0xb] != 0)
          ) && ((iVar1 = *piVar4, 9 < iVar1 && (iVar1 < 0x10)))) {
        if (iVar1 == 0xf) {
          iVar1 = FUN_00562cc0(piVar4[0xb]);
          if (iVar1 != 0) {
            iVar1 = FUN_0056b1c0();
            *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + iVar1;
          }
        }
        else {
          uVar2 = 1;
          if (*(int *)(piVar4[10] + 0x1d0) != 0) {
            puVar3 = (undefined4 *)FUN_00476070(0);
            puVar5 = local_40;
            for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
              *puVar5 = *puVar3;
              puVar3 = puVar3 + 1;
              puVar5 = puVar5 + 1;
            }
            FUN_00477d30(3,&local_a4);
            iVar1 = piVar4[10];
            local_d8 = 0;
            local_d4 = 0;
            local_d0 = 0x3f800000;
            local_c8 = local_a4 - *(float *)(iVar1 + 0x1b8);
            local_c4 = local_a0 - *(float *)(iVar1 + 0x1bc);
            local_c0 = local_9c - *(float *)(iVar1 + 0x1c0);
            local_b0 = local_c8;
            local_ac = local_c4;
            local_a8 = local_c0;
            FUN_0047ec40();
            puVar3 = (undefined4 *)FUN_0047edc0(local_58,&local_d8,&local_c8);
            local_bc = *puVar3;
            local_b8 = puVar3[1];
            local_b4 = puVar3[2];
            FUN_0047ec40();
            puVar3 = (undefined4 *)FUN_0047edc0(local_4c,&local_c8,&local_bc);
            local_d8 = *puVar3;
            local_d4 = puVar3[1];
            local_d0 = puVar3[2];
            FUN_0047ec40();
            FUN_00477200();
            FUN_00477b90(0,&local_bc);
            FUN_00477b90(1,&local_d8);
            FUN_00477b90(2,&local_c8);
            FUN_00477b90(3,piVar4[10] + 0x1b8);
            FUN_00474410();
            thunk_FUN_004e8500(local_98);
            uVar2 = 0;
          }
          iVar1 = (**(code **)(*(int *)piVar4[0xb] + 0xc))(uVar2);
          if (iVar1 != 0) {
            iVar1 = FUN_0056b1c0();
            *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + iVar1;
          }
          if (*(int *)(piVar4[10] + 0x1d0) != 0) {
            FUN_00474470();
          }
        }
      }
      local_cc = local_cc + 1;
      piVar4 = piVar4 + 0x2b;
    } while (local_cc < *(int *)(param_1 + 0x4b0));
  }
  piVar4 = (int *)**(int **)(param_1 + 0x2ac);
  if (piVar4 != *(int **)(param_1 + 0x2ac)) {
    do {
      if (*(int *)(piVar4[2] + 0x2c) != 0) {
        FUN_00562cc0(*(int *)(piVar4[2] + 0x2c));
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)*(int *)(param_1 + 0x2ac));
  }
  return;
}


