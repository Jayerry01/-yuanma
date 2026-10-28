float10 FUN_00596691(double param_1,double param_2,double param_3,double param_4,double param_5,
                    double param_6,double param_7)

{
  double dVar1;
  double dVar2;
  
  dVar1 = param_7 + param_6;
  dVar2 = param_7 * param_7 + param_6 * param_7 + param_6 * param_6;
  return ((float10)param_1 + (float10)((dVar1 - param_5 * 2.0) * param_2 * 0.5) +
          (float10)((dVar2 - (dVar1 - param_5) * param_5 * 3.0) * (param_3 / 3.0)) +
         (float10)(((param_7 * param_7 * param_7 +
                    param_7 * param_7 * param_6 +
                    param_6 * param_6 * param_7 + param_6 * param_6 * param_6) -
                   (dVar2 * 2.0 - (dVar1 * 3.0 - param_5 * 2.0) * param_5) * param_5 * 2.0) *
                  (param_4 / 4.0))) * ((float10)param_7 - (float10)param_6);
}


