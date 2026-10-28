void FUN_00428dd0(void)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint unaff_retaddr;
  int in_stack_00001008;
  int in_stack_0000100c;
  
  FUN_00509ce0();
  if (in_stack_0000100c != 0) {
    unaff_retaddr = FUN_0040e550(0,0,0);
  }
  if (*(int *)(in_stack_00001008 + 4) == 6) {
    iVar1 = 0;
    piVar5 = *(int **)(*(int *)(in_stack_00001008 + 0x9c) + 0x40);
    iVar7 = *(int *)(*(int *)(in_stack_00001008 + 0x9c) + 0x34);
    if (0 < iVar7) {
      do {
        iVar2 = 0;
        if (0 < iVar1) {
          do {
            if (*(int *)(&stack0x00000004 + iVar2 * 4) == piVar5[1]) break;
            iVar2 = iVar2 + 1;
          } while (iVar2 < iVar1);
        }
        if (iVar2 == iVar1) {
          *(int *)(&stack0x00000004 + iVar1 * 4) = piVar5[1];
          iVar1 = iVar1 + 1;
        }
        if (*piVar5 == 1) {
          piVar5 = piVar5 + DAT_005c4314;
        }
        else if (*piVar5 == 2) {
          piVar5 = piVar5 + piVar5[2] * 2 + 3;
        }
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    iVar7 = 0;
    if (0 < iVar1) {
      do {
        iVar2 = (&DAT_007e5be0)[*(int *)(&stack0x00000004 + iVar7 * 4)];
        if ((iVar2 != 0) && (*(int *)(iVar2 + 0x34) != 0)) {
          if (in_stack_0000100c == 0) {
            for (iVar2 = *(int *)(iVar2 + 0x38); iVar2 != 0; iVar2 = *(int *)(iVar2 + 100)) {
              *(undefined4 *)(iVar2 + 0x2c) = 0xffffffff;
            }
          }
          else {
            for (iVar2 = *(int *)(iVar2 + 0x38); iVar2 != 0; iVar2 = *(int *)(iVar2 + 100)) {
              puVar3 = (ushort *)(*(int *)(iVar2 + 0x54) + 0x1e);
              iVar6 = 0;
              if (0 < *(int *)(iVar2 + 0x28)) {
                do {
                  if (*puVar3 == unaff_retaddr) {
                    *(int *)(iVar2 + 0x2c) = iVar6;
                    break;
                  }
                  puVar3 = puVar3 + 0x10;
                  iVar6 = iVar6 + 1;
                } while (iVar6 < *(int *)(iVar2 + 0x28));
              }
            }
          }
        }
        iVar7 = iVar7 + 1;
        if (iVar1 <= iVar7) {
          return;
        }
      } while( true );
    }
  }
  else if (*(int *)(in_stack_00001008 + 4) == 7) {
    uVar4 = *(uint *)(*(int *)(in_stack_00001008 + 0x9c) + 4) & 0xffffff;
    if (in_stack_0000100c == 0) {
      for (iVar7 = *(int *)((&DAT_007e5be0)[uVar4] + 0x38); iVar7 != 0;
          iVar7 = *(int *)(iVar7 + 100)) {
        *(undefined4 *)(iVar7 + 0x2c) = 0xffffffff;
      }
    }
    else {
      iVar7 = *(int *)((&DAT_007e5be0)[uVar4] + 0x38);
      if (iVar7 != 0) {
        do {
          puVar3 = (ushort *)(*(int *)(iVar7 + 0x54) + 0x1e);
          iVar1 = 0;
          if (0 < *(int *)(iVar7 + 0x28)) {
            do {
              if (*puVar3 == unaff_retaddr) {
                *(int *)(iVar7 + 0x2c) = iVar1;
                break;
              }
              puVar3 = puVar3 + 0x10;
              iVar1 = iVar1 + 1;
            } while (iVar1 < *(int *)(iVar7 + 0x28));
          }
          iVar7 = *(int *)(iVar7 + 100);
          if (iVar7 == 0) {
            return;
          }
        } while( true );
      }
    }
  }
  return;
}


