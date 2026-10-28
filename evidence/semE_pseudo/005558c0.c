void FUN_005558c0(undefined4 *param_1,undefined1 param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
    param_1 = param_1 + 1;
  }
  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
    *(undefined1 *)param_1 = param_2;
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x00555901)
// WARNING: Removing unreachable block (ram,0x00555907)
// WARNING: Removing unreachable block (ram,0x00555910)
