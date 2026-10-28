undefined4 FUN_0047c3a0(float param_1,float param_2)

{
  int iVar1;
  
  iVar1 = FUN_0047c1e0(4,2,6);
  if (iVar1 == 0) {
    return 0;
  }
  param_1 = param_1 * 0.5;
  param_2 = param_2 * 0.5;
  FUN_00481b30();
  FUN_00481c20(0,-param_1,-param_2,0);
  FUN_00481cb0(0,0,0,0x3f800000);
  FUN_00481d00(0,0xffffffff);
  FUN_00481d40(0,0,0,0xffffffff);
  FUN_00481c20(1,param_1,-param_2,0);
  FUN_00481cb0(1,0,0,0x3f800000);
  FUN_00481d00(1,0xffffffff);
  FUN_00481d40(1,0x3f800000,0,0xffffffff);
  FUN_00481c20(2,param_1,param_2,0);
  FUN_00481cb0(2,0,0,0x3f800000);
  FUN_00481d00(2,0xffffffff);
  FUN_00481d40(2,0x3f800000,0x3f800000,0xffffffff);
  FUN_00481c20(3,-param_1,param_2,0);
  FUN_00481cb0(3,0,0,0x3f800000);
  FUN_00481d00(3,0xffffffff);
  FUN_00481d40(3,0,0x3f800000,0xffffffff);
  FUN_00481b90();
  FUN_00481b30();
  FUN_00481ee0(0,0);
  FUN_00481ee0(1,1);
  FUN_00481ee0(2,2);
  FUN_00481ee0(3,0);
  FUN_00481ee0(4,2);
  FUN_00481ee0(5,3);
  FUN_00481b90();
  return 1;
}


