#include <stdio.h>
#include <stdlib.h> //rand() y srand()
#include <time.h>   //time()
#include <stdbool.h>
#include "P9.h"


void mensajeP9(bool tipo){
    int msg = generar_aleatoriosP9(1,4);
    if (tipo) {
        switch (msg)
        {
        case 1:
            printf("\nMuy bien!\n");
            break;

        case 2:
            printf("\nExcelente!\n");
            break;

        case 3:
            printf("\nBuen trabajo!\n");
            break;
            
        case 4:
            printf("\nSigue haciéndolo bien!\n");
            break;
        
        default:
            break;
        }
    } else {
        switch (msg)
        {
        case 1:
            printf("\nNo. Por favor trata de nuevo.\n");
            break;

        case 2:
            printf("\nIncorrecto. Trata una vez más.\n");
            break;

        case 3:
            printf("\nNo te rindas!\n");
            break;
            
        case 4:
            printf("\nNo. Trata de nuevo\n");
            break;
        
        default:
            break;
        }
    }
}

bool preguntaP9(int a, int b) {
    int res;

    printf("\n¿Cuánto es %d veces %d?\n", a, b);
    scanf("%d", &res);

    return a*b == res;
}

int mayorP9(int num1, int num2) {
    if(num1 >= num2) {
        return num1;
    }
    else {
        return num2;
    }
}

int menorP9(int num1, int num2) {
    if(num1 <= num2) {
        return num1;
    }
    else {
        return num2;
    }
}

int generar_aleatoriosP9(int num1, int num2) {
    int cnt = 0, num, M, m;

    M = mayorP9(num1, num2);
    m = menorP9(num1, num2);

    return rand()%(M - m + 1) + m;
}