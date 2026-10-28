undefined4 FUN_00473860(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_7c [31];
  
  if ((DAT_005e037c != 0) && (DAT_005e0380 != (int *)0x0)) {
    puVar1 = local_7c;
    for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    }
    local_7c[0] = 0x7c;
    (**(code **)(*DAT_005e0380 + 100))(DAT_005e0380,0,local_7c,1,0);
    (**(code **)(*DAT_005e0380 + 0x80))(DAT_005e0380,0);
    return 1;
  }
  return 0;
}


