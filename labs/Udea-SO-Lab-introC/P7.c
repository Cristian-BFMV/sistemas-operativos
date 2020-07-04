#include <stdio.h>
#include "P7.h"


int reverse(int n){
  int reversed = 0;

  while (n > 0) {
    reversed = reversed*10 + n%10;
    n = n/10; 
  }
  return reversed;
}