void __thiscall FUN_0047ddb0(float param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  int iVar2;
  float local_4;
  
  local_4 = param_1;
  FUN_00481b30();
  fVar1 = param_4;
  iVar2 = 0;
  if (0 < *(int *)((int)param_1 + 4)) {
    do {
      FUN_00481e70(iVar2,&local_4,&param_4,fVar1);
      FUN_00481d40(iVar2,local_4 + param_2,param_4 + param_3,fVar1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)param_1 + 4));
  }
  FUN_00481b90();
  return;
}


