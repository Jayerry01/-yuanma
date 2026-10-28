void FUN_00403f10(void)

{
  double dVar1;
  code *pcVar2;
  double *pdVar3;
  float10 fVar4;
  int iVar5;
  
  fVar4 = (float10)FUN_00412620();
  dVar1 = (double)fVar4;
  pdVar3 = (double *)&DAT_007f16c0;
  do {
    if ((*(int *)(pdVar3 + -4) != 0) && (pcVar2 = *(code **)(pdVar3 + 1), pcVar2 != (code *)0x0)) {
      if (*(int *)((int)pdVar3 + -0x1c) == 0) {
        if (*(int *)(pdVar3 + -3) == 0) goto LAB_00403f62;
        if (dVar1 < *pdVar3) {
          if (dVar1 < pdVar3[-2]) {
            *(undefined4 *)((int)pdVar3 + -0x1c) = 1;
          }
          goto LAB_00403f68;
        }
        iVar5 = __ftol();
        iVar5 = iVar5 + 1;
        *pdVar3 = (double)iVar5 * pdVar3[-1] + *pdVar3;
        if (iVar5 < 4) {
          if (iVar5 < 1) {
            iVar5 = 1;
            *(undefined4 *)((int)pdVar3 + -0x1c) = 1;
          }
        }
        else {
          if (500 < iVar5) {
            *(undefined4 *)((int)pdVar3 + -0x1c) = 1;
          }
          iVar5 = 3;
        }
      }
      else {
        *(undefined4 *)((int)pdVar3 + -0x1c) = 0;
        pdVar3[-2] = dVar1;
        *pdVar3 = dVar1 + pdVar3[-1];
LAB_00403f62:
        iVar5 = 1;
      }
      (*pcVar2)(iVar5);
    }
LAB_00403f68:
    pdVar3 = pdVar3 + 6;
    if (0x7f183f < (int)pdVar3) {
      return;
    }
  } while( true );
}


