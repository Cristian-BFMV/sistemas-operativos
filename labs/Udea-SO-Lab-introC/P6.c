#include <stdio.h>
#include <math.h>
#include "P6.h"


float serie(int x, int n) {
  float acum = 0;

  for (int i = 0; i < n; i++) {
    acum += pow(-1, i) * pow(x, i*2) / factorial(i*2);
  }
  return acum;
}


int factorial(int n){
  int acum = 1;

  for (int i = 1; i <= n; i++){
    acum *= i;
  }
  return acum;
}