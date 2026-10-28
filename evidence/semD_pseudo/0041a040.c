char FUN_0041a040(float *param_1,float *param_2,float *param_3,float param_4)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  char cVar4;
  
  cVar4 = param_4 <= *param_1 * *param_3 + param_1[1] * param_3[1] + param_1[2] * param_3[2];
  bVar1 = param_4 <= *param_2 * *param_3 + param_2[1] * param_3[1] + param_2[2] * param_3[2];
  bVar3 = cVar4;
  if ((bool)cVar4 != bVar1) {
    bVar3 = cVar4 + 1;
  }
  if (bVar1) {
    cVar4 = cVar4 + '\x01';
    bVar3 = bVar3 + 1;
  }
  cVar2 = '\0';
  if (1 < bVar3) {
    cVar2 = (cVar4 == '\x02') + '\x01';
  }
  return cVar2;
}


