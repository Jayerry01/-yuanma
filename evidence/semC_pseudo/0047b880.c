void __thiscall FUN_0047b880(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_2 != 0) {
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    puVar2 = (undefined4 *)(param_1 + 0x14);
    puVar3 = (undefined4 *)(param_2 + 0x14);
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = (undefined4 *)(param_1 + 0x54);
    puVar3 = (undefined4 *)(param_2 + 0x54);
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = (undefined4 *)(param_1 + 0x94);
    puVar3 = (undefined4 *)(param_2 + 0x94);
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    *(undefined4 *)(param_2 + 0xd4) = *(undefined4 *)(param_1 + 0xd4);
    *(undefined1 *)(param_2 + 0xd8) = *(undefined1 *)(param_1 + 0xd8);
    *(undefined1 *)(param_2 + 0xd9) = *(undefined1 *)(param_1 + 0xd9);
    *(undefined1 *)(param_2 + 0xda) = *(undefined1 *)(param_1 + 0xda);
    *(undefined4 *)(param_2 + 0xe4) = *(undefined4 *)(param_1 + 0xe4);
    *(undefined4 *)(param_2 + 0xe8) = *(undefined4 *)(param_1 + 0xe8);
    *(undefined4 *)(param_2 + 0xec) = *(undefined4 *)(param_1 + 0xec);
    *(undefined4 *)(param_2 + 0xf0) = *(undefined4 *)(param_1 + 0xf0);
    *(undefined4 *)(param_2 + 0xf4) = *(undefined4 *)(param_1 + 0xf4);
    *(undefined4 *)(param_2 + 0xf8) = *(undefined4 *)(param_1 + 0xf8);
    *(undefined4 *)(param_2 + 0xfc) = *(undefined4 *)(param_1 + 0xfc);
    *(undefined4 *)(param_2 + 0x100) = *(undefined4 *)(param_1 + 0x100);
    *(undefined4 *)(param_2 + 0x104) = *(undefined4 *)(param_1 + 0x104);
    *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(param_1 + 0x108);
    *(undefined4 *)(param_2 + 0x10c) = *(undefined4 *)(param_1 + 0x10c);
    *(undefined4 *)(param_2 + 0x110) = *(undefined4 *)(param_1 + 0x110);
    *(undefined4 *)(param_2 + 0x114) = *(undefined4 *)(param_1 + 0x114);
    *(undefined4 *)(param_2 + 0x118) = *(undefined4 *)(param_1 + 0x118);
    *(undefined4 *)(param_2 + 0x11c) = *(undefined4 *)(param_1 + 0x11c);
    if (*(int *)(param_1 + 0xd4) != 0) {
      FUN_0047ba50();
      return;
    }
  }
  return;
}


