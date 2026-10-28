void __fastcall FUN_005847f0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*(char *)(*(int *)(param_1 + 8) + 0x58) != '\0') {
    iVar1 = *(int *)(param_1 + 0x274);
    if (iVar1 != 0) {
      FUN_0055beb0();
      FUN_00507850(iVar1);
      *(undefined4 *)(param_1 + 0x274) = 0;
    }
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x91c)) {
      piVar2 = (int *)(param_1 + 0x278);
      do {
        if ((int *)*piVar2 != (int *)0x0) {
          (**(code **)(*(int *)*piVar2 + 8))(1);
          *piVar2 = 0;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x91c));
    }
  }
  return;
}


