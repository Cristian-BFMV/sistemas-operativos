#include <stdio.h>
#include "P2.h"

int tablas()
{
    int ultimo;
    printf("%s", "\nEscriba el número final de las tablas que quiere visualizar: ");
    scanf("%d", &ultimo);

    for (size_t i = 0; i < 10; i++)
    {
        printf("\nTabla del %ld ",i);
        for (size_t j = 1; j <= ultimo; j++)
        {
            printf(" %ldx%ld = %ld,",i,j,i*j);
        }
        
    } 
    printf("%s", "\n");
}