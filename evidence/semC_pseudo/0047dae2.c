FUN_0047dae2(float param_1,float param_2,float param_3,undefined4 param_4,float param_5,
            undefined4 param_6,float param_7,undefined4 param_8,int param_9,float param_10,
            float param_11)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  param_6 = param_9;
  iVar2 = 0;
  iVar1 = 0;
  FUN_00481b30();
  FUN_00481b30();
  if (0 < param_9) {
    param_9 = 2;
    do {
      FUN_00481c20(iVar2,param_1,-param_2,0);
      FUN_00481cb0(iVar2,0,0,0x3f800000);
      FUN_00481d00(iVar2,0xffffffff);
      FUN_00481d40(iVar2,param_3,0,0xffffffff);
      iVar3 = iVar2 + 1;
      FUN_00481c20(iVar3,param_10,-param_2,0);
      FUN_00481cb0(iVar3,0,0,0x3f800000);
      FUN_00481d00(iVar3,0xffffffff);
      FUN_00481d40(iVar3,param_11,0,0xffffffff);
      iVar3 = iVar2 + 2;
      FUN_00481c20(iVar3,param_10,param_2,0);
      FUN_00481cb0(iVar3,0,0,0x3f800000);
      FUN_00481d00(iVar3,0xffffffff);
      FUN_00481d40(iVar3,param_11,0x3f800000,0xffffffff);
      iVar3 = iVar2 + 3;
      FUN_00481c20(iVar3,param_1,param_2,0);
      FUN_00481cb0(iVar3,0,0,0x3f800000);
      FUN_00481d00(iVar3,0xffffffff);
      FUN_00481d40(iVar3,param_3,0x3f800000,0xffffffff);
      param_1 = param_10;
      iVar2 = iVar2 + 4;
      param_3 = param_11;
      FUN_00481ee0(iVar1,param_9 + -2);
      FUN_00481ee0(iVar1 + 1,param_9 + -1);
      FUN_00481ee0(iVar1 + 2,param_9);
      FUN_00481ee0(iVar1 + 3,param_9 + -2);
      iVar3 = iVar1 + 5;
      FUN_00481ee0(iVar1 + 4,param_9);
      iVar1 = iVar1 + 6;
      FUN_00481ee0(iVar3,param_9 + 1);
      param_9 = param_9 + 4;
      param_6 = param_6 + -1;
      param_10 = param_10 + param_5;
      param_11 = param_11 + param_7;
    } while (param_6 != 0);
  }
  FUN_00481b90();
  FUN_00481b90();
  return 1;
}



void __thiscall