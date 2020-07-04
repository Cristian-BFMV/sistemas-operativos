#include <stdio.h>
#include <math.h>
#include "P5.h"


double serieP5(double x, double n) {
  double acum = 0;

  for (int i = 0; i <= n; i++) {
    acum += pow(x, i);
  }
  return acum;
}


int factorialP5(int n){
  int acum = 1;

  for (int i = 1; i <= n; i++){
    acum *= i;
  }
  return acum;
}