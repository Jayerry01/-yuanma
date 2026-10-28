undefined4 __thiscall FUN_00594177(undefined4 param_1,double param_2)

{
  uint uVar1;
  float10 fVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_005937aa(param_2,param_1,param_1);
  if ((uVar1 & 0x90) == 0) {
    fVar2 = (float10)__frnd(param_2);
    if ((double)fVar2 == param_2) {
      fVar2 = (float10)__frnd();
      if (fVar2 == (float10)(param_2 / 2.0)) {
        uVar3 = 2;
      }
      else {
        uVar3 = 1;
      }
      return uVar3;
    }
  }
  return 0;
}



// Library Function - Single Match
//  __cintrindisp2
// 
// Library: Visual Studio

void __cintrindisp2(void)

{
  __trandisp2();
  FUN_005942aa();
  return;
}



// Library Function - Single Match
//  __cintrindisp1
// 
// Library: Visual Studio

void __cintrindisp1(void)

{
  __trandisp1();
  FUN_005942aa();
  return;
}



// Library Function - Single Match
//  __ctrandisp2
// 
// Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2005, Visual Studio 2008

void __ctrandisp2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  __fload(param_1,param_2);
  __fload(param_3,param_4);
  __trandisp2();
  FUN_005942a3();
  return;
}


