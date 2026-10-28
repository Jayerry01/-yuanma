undefined4 __thiscall FUN_004698c0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int in_stack_0000001c;
  int aiStack_48 [5];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 local_14 [4];
  undefined4 local_4;
  
  puVar4 = (undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 8) = param_2;
  iVar2 = *(int *)(param_1 + 0x38);
  puVar3 = (undefined4 *)&stack0x00000008;
  puVar5 = puVar4;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  local_14[0] = *puVar4;
  local_14[1] = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0xc) = 0;
  local_4 = 0x3f800000;
  if (iVar2 == 2) {
    local_14[2] = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x28) = local_14[1];
    uStack_28 = 0x46991d;
    local_14[3] = local_14[2];
    uStack_28 = __ftol();
    uStack_2c = 0x469926;
    uStack_2c = __ftol();
    uStack_30 = 0x469935;
    uStack_30 = __ftol();
  }
  else {
    local_14[2] = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x28) = *puVar4;
    uStack_28 = 0x469956;
    local_14[3] = local_14[2];
    uStack_28 = __ftol();
    uStack_2c = 0x46995f;
    uStack_2c = __ftol();
    uStack_30 = 0x46996b;
    uStack_30 = __ftol();
  }
  uStack_34 = 0x46997a;
  uStack_34 = __ftol();
  puVar4 = local_14;
  piVar6 = aiStack_48;
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    piVar6 = piVar6 + 1;
  }
  FUN_00469f70();
  aiStack_48[4] = in_stack_0000001c;
  *(undefined4 *)(param_1 + 0x70) = 0;
  if (in_stack_0000001c != 0) {
    uStack_28 = 0;
    uStack_2c = 0x4699a9;
    FUN_00429990();
    uStack_2c = 0x4699b2;
    uStack_2c = __ftol();
    uStack_30 = 0x4699bc;
    uStack_30 = __ftol();
    uStack_34 = 0;
    aiStack_48[3] = 0x4699c5;
    FUN_00429aa0();
    aiStack_48[3] = 0;
    aiStack_48[2] = 0x4699cc;
    iVar2 = FUN_00429c30();
    *(int *)(param_1 + 0x70) = iVar2;
    aiStack_48[2] = 0x4699da;
    aiStack_48[2] = __ftol();
    aiStack_48[1] = 0x4699e4;
    aiStack_48[1] = __ftol();
    aiStack_48[0] = iVar2;
    FUN_00429d00();
  }
  return 1;
}


