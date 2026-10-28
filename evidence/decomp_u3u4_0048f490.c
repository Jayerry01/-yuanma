
void __thiscall FUN_0048f490(int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 unaff_retaddr;
  undefined4 uVar5;
  undefined ***pppuVar6;
  int iStack_78;
  int iStack_74;
  undefined4 auStack_70 [3];
  undefined1 auStack_64 [12];
  undefined **appuStack_58 [11];
  int iStack_2c;
  int *piStack_28;
  int *piStack_24;
  void *pvStack_10;
  void *pvStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = thunk_ilt_0059E590;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0049d3c0(auStack_70,&param_2);
  iVar2 = (**(code **)(*param_1 + 300))(param_2);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = iVar2 + -0x65c;
  }
  if ((iStack_74 != param_1[0x8bb]) && (iVar2 != 0)) {
    FUN_00492000();
    pcStack_8 = (code *)0x0;
    FUN_005005b0(&stack0xffffff87);
    appuStack_58[0] = &PTR_FUN_005a9488;
    pppuVar6 = appuStack_58;
    pcStack_8 = (code *)0x1;
    iStack_78 = 0;
    uVar5 = param_2;
    iVar2 = param_3;
    FUN_004d6570(param_2,param_3,pppuVar6);
    FUN_004d65c0(uVar5,iVar2,pppuVar6);
    iVar2 = (**(code **)(*(int *)(iStack_74 + 0x88) + 0x24))(appuStack_58,&iStack_78);
    if (iVar2 != 0) {
      for (; piStack_28 != piStack_24; piStack_28 = piStack_28 + 3) {
        if (*piStack_28 == 0xe) {
          if ((piStack_28 != piStack_24) && (piStack_28 != (int *)0x0)) {
            (**(code **)(*param_1 + 0x20c))(unaff_retaddr,piStack_28[1],0,0);
          }
          break;
        }
      }
      if ((iVar2 == 1) && (iStack_78 != 0)) {
        piVar4 = *(int **)(iStack_78 + 0x30);
        piVar1 = *(int **)(iStack_78 + 0x34);
        if (piVar4 != piVar1) {
          do {
            if (*piVar4 == 0xf) break;
            piVar4 = piVar4 + 3;
          } while (piVar4 != piVar1);
          if (((piVar4 != piVar1) && (piVar4 != (int *)0x0)) && (piVar4[1] != 0)) {
            (**(code **)(*param_1 + 0x20c))(unaff_retaddr,piVar4[1],1,&param_3);
            piVar4[2] = param_3;
          }
        }
      }
      if (iStack_2c == 4) {
        FUN_00402b70(&param_3,8);
        pcStack_8._0_1_ = 2;
        FUN_00402a70();
        pcStack_8._0_1_ = 3;
        FUN_004ab200(auStack_70);
        puVar3 = (undefined4 *)FUN_0049dc30(auStack_64,auStack_70,&DAT_005c462c);
        pcStack_8._0_1_ = 4;
        if (puVar3 != auStack_70) {
          FUN_00403200(*puVar3,puVar3[1]);
        }
        pcStack_8._0_1_ = 3;
        FUN_00402bd0();
        puVar3 = (undefined4 *)FUN_0049de10(auStack_64,auStack_70,param_1[0x912] + 0x6c);
        pcStack_8._0_1_ = 5;
        if (puVar3 != auStack_70) {
          FUN_00403200(*puVar3,puVar3[1]);
        }
        pcStack_8._0_1_ = 3;
        FUN_00402bd0();
        (**(code **)(*param_1 + 0xfc))(auStack_70[0],0);
        pcStack_8 = (code *)CONCAT31(pcStack_8._1_3_,1);
        FUN_00402bd0();
      }
    }
    pcStack_8 = (code *)0xffffffff;
    FUN_0048f240();
  }
  ExceptionList = pvStack_10;
  return;
}

