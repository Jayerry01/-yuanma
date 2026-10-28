void FUN_0052bf60(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  if ((param_1 < 1) || (param_2 == 0)) {
    FUN_00530d00(0x505);
  }
  else if ((DAT_00723270 != 0) || (cVar2 = FUN_0052c520(), cVar2 != '\0')) {
joined_r0x0052bf9c:
    do {
      if (DAT_00723274 == (int *)0x0) {
LAB_0052bffe:
        if ((DAT_00723264 <= DAT_00723268) && (cVar2 = FUN_0052c520(), cVar2 == '\0')) {
          return;
        }
        *(uint *)(param_2 + iVar4 * 4) = DAT_00723268;
        uVar3 = FUN_0052c740(1,1,1,1,1);
        *(undefined4 *)(DAT_00723270 + DAT_00723268 * 4) = uVar3;
        DAT_00723268 = DAT_00723268 + 1;
      }
      else {
        piVar1 = (int *)DAT_00723274[1];
        if (*(int *)(DAT_00723270 + *DAT_00723274 * 4) != 0) {
          FUN_00530db0(DAT_00723274);
          DAT_00723274 = piVar1;
          goto joined_r0x0052bf9c;
        }
        *(int *)(param_2 + iVar4 * 4) = *DAT_00723274;
        uVar3 = FUN_0052c740(1,1,1,1,1);
        *(undefined4 *)(DAT_00723270 + *DAT_00723274 * 4) = uVar3;
        FUN_00530db0(DAT_00723274);
        DAT_00723274 = piVar1;
        if (piVar1 == (int *)0x0) goto LAB_0052bffe;
      }
      iVar4 = iVar4 + 1;
      if (param_1 <= iVar4) {
        return;
      }
    } while( true );
  }
  return;
}


