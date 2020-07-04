#include <stdio.h>
#include <math.h>
#include <stdlib.h> //rand() y srand()
#include <time.h>   //time()
#include <stdbool.h>
#include "P8.h"

bool preguntaP8(int a, int b) {
    int res;

    printf("\n¿Cuánto es %d veces %d?\n", a, b);
    scanf("%d", &res);

    return a*b == res;
}

int mayorP8(int num1, int num2) {
    if(num1 >= num2) {
        return num1;
    }
    else {
        return num2;
    }
}

int menorP8(int num1, int num2) {
    if(num1 <= num2) {
        return num1;
    }
    else {
        return num2;
    }
}

int generar_aleatoriosP8(int num1, int num2) {
    int cnt = 0, num, M, m;

    M = mayorP8(num1, num2);
    m = menorP8(num1, num2);

    return rand()%(M - m + 1) + m;
}