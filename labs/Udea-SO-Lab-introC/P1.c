#include <stdio.h>
#include "P1.h"

int comisiones(int ventas)
{
    float porcent1 = 0.05;
    float porcent2 = 0.07;
    float porcent3 = 0.1;

    if (ventas <= 20000 && ventas >= 0){
        float valor_calculado = ventas * porcent1;
        printf("\nLa comision de %d es de: %f", ventas, valor_calculado);
    }
    else if (ventas >= 20000 && ventas < 50000){
        float valor_calculado = ventas * porcent2+1000;
        printf("\nLa comision de %d es de: %f", ventas, valor_calculado);
    }
    else if (ventas >= 50000){
        float valor_calculado = ventas * porcent3+3100;
        printf("\nLa comision de %d es de: %f", ventas, valor_calculado);
    }
    else{
        printf("%s", "\nError: el valor esperado debe ser superior a 0\n");
    }

    return 0;
}
