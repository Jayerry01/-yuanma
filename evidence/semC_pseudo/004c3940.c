void __thiscall FUN_004c3940(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined1 auStack_c [12];
  
  iVar2 = FUN_00487830();
  uVar3 = (**(code **)(*(int *)(iVar2 + 0x2488) + 0x4c))();
  if (param_2 == uVar3) {
    FUN_00477200();
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_1c = 0x3f800000;
    FUN_00501600((float)*(int *)(param_1 + 0x574),&uStack_18);
    FUN_00529c40(&uStack_18,&uStack_24,auStack_c);
    FUN_00477b90(0,auStack_c);
    FUN_00477b90(1,&uStack_18);
    FUN_00477b90(2,&uStack_24);
    iVar2 = *(int *)(param_1 + 0x570);
LAB_004c3af2:
    iVar2 = FUN_004c2bf0(iVar2);
    uStack_30 = *(undefined4 *)(iVar2 + 4);
    uStack_2c = *(undefined4 *)(iVar2 + 8);
    fStack_28 = *(float *)(iVar2 + 0xc) - 29.0;
    FUN_00477c10(3,&uStack_30);
  }
  else {
    piVar4 = (int *)**(int **)(iVar2 + 0x2960);
    if (piVar4 != *(int **)(iVar2 + 0x2960)) {
      do {
        piVar1 = (int *)piVar4[2];
        if (piVar1 != (int *)0x0) {
          uVar3 = (**(code **)(*piVar1 + 0x4c))();
          if (uVar3 == param_2) {
            if (((-1 < (int)param_2) &&
                (param_2 < (uint)((*(int *)(param_1 + 0x51c) - *(int *)(param_1 + 0x518)) / 0x124)))
               && (*(int *)(*(int *)(param_1 + 0x518) + param_2 * 0x124 + 4) == 3)) {
              FUN_004fb730();
            }
            FUN_00477200();
            uStack_24 = 0;
            uStack_20 = 0x3f800000;
            uStack_1c = 0;
            uStack_18 = 0;
            uStack_14 = 0;
            uStack_10 = 0x3f800000;
            FUN_00529c40(&uStack_24,&uStack_18,auStack_c);
            FUN_00477b90(0,auStack_c);
            FUN_00477b90(1,&uStack_24);
            FUN_00477b90(2,&uStack_18);
            iVar2 = (int)(short)piVar1[0x112];
            goto LAB_004c3af2;
          }
        }
        piVar4 = (int *)*piVar4;
        if (piVar4 == (int *)*(int *)(iVar2 + 0x2960)) {
          return;
        }
      } while( true );
    }
  }
  return;
}


