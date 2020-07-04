#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> //rand() y srand()
#include <time.h>   //time()
#include "P1.h"
#include "P2.h"
#include "P3.h"
#include "P4.h"
#include "P5.h"
#include "P6.h"
#include "P7.h"
#include "P8.h"
#include "P9.h"
#include "P10.h"

int main()
{
    int ejercicio;
    int x, n;
    double y,z;
    float res;
    double resP5;
    int num_pares, min, max, a, b, continuar;

    printf("%s", "\nEscriba el número del ejercicio que quiere visualizar: ");
    scanf("%d", &ejercicio);
    switch (ejercicio)
    {
    case 1:
        comisiones(20000);
        comisiones(20001);
        comisiones(30000);
        comisiones(50000);
        comisiones(50001);
        comisiones(75000);
        comisiones(-3);
        break;
    case 2:
        tablas();
        break;
    case 3:
        secuencia();
        break;
    case 4:

        do
        {
            printf("Ingrese el primer número:\t");
            scanf("%d", &x);

            printf("Ingrese el segundo número:\t");
            scanf("%d", &n);

            if (multiplo(x, n))
            {
                printf("%d es múltiplo de %d", n, x);
            }
            else
            {
                printf("%d no es múltiplo de %d", n, x);
            }

            printf("\t\t\tPresione CTRL + C para terminar el proceso\n");
        } while (1);
        break;
    case 5:
        printf("Valor de entrada de x:\t");
        scanf("%le", &y);

        printf("Número de términos:\t");
        scanf("%le", &z);

        resP5 = serieP5(y, z);
        printf("\nsuma:\t%f\n", resP5);
        break;
    case 6:
        printf("Valor de entrada de x:\t");
        scanf("%d", &x);

        printf("Número de términos:\t");
        scanf("%d", &n);

        res = serie(x, n);
        printf("\nsuma:\t%f\n", res);
        break;
    case 7:
        printf("Digite el número\n");
        scanf("%d", &x);

        x = reverse(x);
        printf("El número al revés es %d\n", x);
        break;
    case 8:
        srand(time(NULL)); //genera la semilla
        min = 0;
        max = 10;
        continuar = 1;

        a = generar_aleatoriosP8(min, max);
        b = generar_aleatoriosP8(min, max);

        while (continuar)
        {
            if (preguntaP8(a, b))
            {
                printf("\nMuy bien!\n");
                a = generar_aleatoriosP8(min, max);
                b = generar_aleatoriosP8(min, max);
            }
            else
            {
                printf("\nNo. Por favor intenta nuevamente\n");
            }
            printf("\n\t\t... ¿Deseas continuar?\n");
            printf("\n\t\t... 1. Sí\t\t0. No\n");
            scanf("%d", &continuar);
        }
        break;
    case 9:
        srand(time(NULL)); //genera la semilla
        min = 0;
        max = 10;
        continuar = 1;

        a = generar_aleatoriosP9(min, max);
        b = generar_aleatoriosP9(min, max);

        while (continuar)
        {
            if (preguntaP9(a, b))
            {
                mensajeP9(true);
                a = generar_aleatoriosP9(min, max);
                b = generar_aleatoriosP9(min, max);
            }
            else
            {
                mensajeP9(false);
            }
            printf("\n\t\t... ¿Deseas continuar?\n");
            printf("\n\t\t... 1. Sí\t\t0. No\n");
            scanf("%d", &continuar);
        }
        break;
    case 10:
        srand(time(NULL)); //genera la semilla
        int num_pares, min, max, a, b, aciertos, errores, continuar;
        min = 0;
        max = 10;
        aciertos = 0;
        errores = 0;
        continuar = 1;

        a = generar_aleatorios(min, max);
        b = generar_aleatorios(min, max);

        while (continuar)
        {
            if (pregunta(a, b))
            {
                mensaje(true);
                aciertos++;
                a = generar_aleatorios(min, max);
                b = generar_aleatorios(min, max);
            }
            else
            {
                mensaje(false);
                errores++;
            }
            printf("\n\t\t... ¿Deseas continuar?\n");
            printf("\n\t\t... 1. Sí\t\t0. No\n");
            scanf("%d", &continuar);
        }

        float porcentaje = aciertos / (float)(aciertos + errores);
        printf("Aciertos: %d\tErrores: %d", aciertos, errores);
        printf("\nAcertaste un %f porciento de las preguntas.", porcentaje);

        if (porcentaje < 0.75f)
        {
            printf("\nPor favor pídele ayuda al instructor.\n");
        }
        break;

    default:
        printf("%s", "\nEjercicio no encontrado\n");
        break;
    }
}