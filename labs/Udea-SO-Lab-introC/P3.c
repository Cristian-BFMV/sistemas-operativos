#include <stdio.h>
#include "P3.h"

int secuencia() {
    int n;
    printf("%s", "\nEscriba el número de caracteres que tendra la secuencia: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if ( (i+j) % 2 == 0) {
                printf("1");
            } else {
                printf("0");
            }
        };
        printf("\n");
    }
}