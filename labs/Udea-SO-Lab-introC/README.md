# Actividades de entrega de los laboratorios

## Pasos previos

Inicialmente antes de empezar este laboratorio haga un **fork**. Luego descarguelo trabajelo localmente y luego actualice su repositorio con la solución. El enlace de este sera el enviado como solución del laboratorio.

## Enunciado del laboratorio

## Ejercicios de repaso

### Parte 1

**P1**. El propietario de Harry’s Car Sales paga a cada vendedor una comisión basada en sus ventas trimestrales. Los rangos de ventas y las correspondientes tasas son mostrades en la tabla que aparece a continuación:

| Ventas trimestrales ($) | Comisión |
|---|---|
| 0 - 20000 |  Multiplicar las ventas por 5% |
|  20001-50000 | Multiplicar la ventas sobre 20000 por 7% y entonces agregue 1000 al resultado |
|  50001 o mas | Multiplicar la ventas sobre 50000 por 10% y entonces agregue 3100 al resultado  | 

Teniendo en cuenta lo anterior lleve a cabo las siguientes tareas:
* Comprenda el problema y realice casos de obteniendo las comisiones para los siguientes valores de ventas: 20000, 20001, 30000, 50000, 50001, 75000, y –3.
* Codifique el algoritmo en C de modo que permita el calculo de las comisiones. Lleve a cabo las pruebas con los casos de test elegidos en el item anterior.

**P1**. Escriba un programa en C para desplegar la tabla de multiplicación desde 1 hasta N.

Test de entrada:

```
Numero final (empezando de 1): 8
```
Salida esperada:

```
Tabla de multiplicación desde 1 hasta 8:

1x1 = 1, 2x1 = 2, 3x1 = 3, 4x1 = 4, 5x1 = 5, 6x1 = 6, 7x1 = 7, 8x1 = 8
...
1x10 = 10, 2x10 = 20, 3x10 = 30, 4x10 = 40, 5x10 = 50, 6x10 = 60, 7x10 = 70, 8x10 = 80
```

**P2**. Escriba un programa en C para imprimir la siguiente secuencia (dado el numero de renglones):

```
1
01
101
0101
10101
```

**P3**. Escriba una función llamada múltiplo que tome dos enteros y determine si el segundo es múltiplo del primero. La función deberá tomar dos argumentos enteros y devolver 1 si el segundo es un múltiplo del primero y 0 si no. Luego, utilice esta función en un programa que acepte como entrada una serie de pares de enteros.

**P4**. Escribir un programa que lea dos números **x** y **n** y en una función, calcule la suma de la progresión geométrica: 

```
1 + x + x^2 + x^3 + x^4 + ⋯ + x^n
```

**P5**. Escriba un programa en C para encontrar la suma de las series: 

```
1 - x^2/2! + x^4/4! - ...
```

Test data:
```
Valor de entrada de x: 2
Numero de terminos: 5
```

Salida esperada:

```
suma: -0.415873
```

**P6**. Escriba una función que tome un valor entero y devuelva el número con sus dígitos en reversa. Por ejemplo, dado el numero 7631, la función deberá devolver 1367.


### Parte 2

Observe los siguientes enunciados y sus soluciones:

**E1**. Hacer una función que solicite 2 números, luego, genere 10 números aleatorios entre estos 2 números y cuente la cantidad de números pares.

**Solución**:

```C

#include <stdio.h>
#include <stdlib.h> //rand() y srand()
#include <time.h>   //time()


int mayor(int num1, int num2);
int menor(int num1, int num2);
int generar_aleatorios(int num1, int num2, int num_aleatorios);

int main (void) {
    srand(time(NULL)); //genera la semilla
    int num_pares, min, max;
    printf("Digite los dos limites (minimo maximo): ");
    scanf("%d %d", &min, &max);
    
    num_pares = generar_aleatorios(min, max, 10);
    putchar('\n');
    printf("La cantidad de numeros pares generados es de: %d\n", num_pares);
    return 0;
}

int mayor(int num1, int num2) {
    if(num1 >= num2) {
        return num1;
    }
    else {
        return num2;
    }
}

int menor(int num1, int num2) {
    if(num1 <= num2) {
        return num1;
    }
    else {
        return num2;
    }
}

int generar_aleatorios(int num1, int num2, int num_aleatorios) {
    int cnt = 0, num, M, m;    
    M = mayor(num1, num2);
    m = menor(num1, num2);
    for(int i = 0; i < num_aleatorios; i++) {
        num = rand()%(M - m + 1) + m;
        if(num % 2 == 0) {
            cnt++;
        }
        printf("%d ", num);
    }    
    return cnt;
}
```

**E2**. Escriba un programa que simule el lanzamiento de una moneda. En cada línea de entrada aparece el número de lanzamientos de la moneda. En la línea de salida correspondiente debe aparecer una secuencia con el resultado de cada lanzamiento ('C' cuando fue cara y 'S' cuando fue sello) junto con el número de veces que aparece cada lado. El programa deberá usar una función que se encargue de simular el lanzamiento de la moneda una sola vez, se recomienda que use la función anteriormente creada. Las salidas pueden ser 0 para la cara ('C') ó 1 para el sello ('S').

La siguiente tabla muestra los ejemplos de algunos casos de entrada y salida:

|Número de lanzamientos | Salida |
|---|--|
|5 |CCSSS, #de caras = 2, # de sellos = 3|
|8 |SCCSCSCC, #de caras = 5, # de sellos = 3|
|5 |SCSCC, # de caras = 3, # de sellos = 2|

**Solución**:

```C

#include <stdio.h>
#include <stdlib.h> //rand() y srand()
#include <time.h>   //time()


int mayor(int num1, int num2);
int menor(int num1, int num2);
int generar_aleatorios(int num1, int num2);
void imprimir_moneda(int lado);

int main (void) {
    srand(time(NULL)); //genera la semilla
    int lanzamientos, lado;
    int num_caras = 0, num_sellos = 0;
    printf("Digite el numero de lanzamientos: ");
    scanf("%d", &lanzamientos);
    for (int i = 0; i < lanzamientos; i++) {
        lado = generar_aleatorios(0,1);
        if (lado == 1) {
            num_sellos++;            
        }
        else {
            num_caras++;
        }
        imprimir_moneda(lado);
    }
    printf(", #de caras = %d, # de sellos = %d\n",num_caras,num_sellos);
    return 0;
}

int mayor(int num1, int num2) {
    if(num1 >= num2) {
        return num1;
    }
    else {
        return num2;
    }
}

int menor(int num1, int num2) {
    if(num1 <= num2) {
        return num1;
    }
    else {
        return num2;
    }
}

int generar_aleatorios(int num1, int num2) {
    int num, M, m;
    
    M = mayor(num1, num2);
    m = menor(num1, num2);    
    num = rand()%(M - m + 1) + m;
    return num;
}

void imprimir_moneda(int lado) {
    if(lado == 1) {
        printf("S");
    }
    else {
        printf("C");
    }
}
```

Analizando los códigos **E1** y **E2** anteriormente mostrados y reciclando aquello que le pueda ser util en haras del reuso, resolver los siguientes problemas:

**P7**. Las computadoras están jugando un papel creciente en la educación. Escriba un programa que ayudaría a un alumno de escuela primaria a aprender a multiplicar (tablas entre 1 y 10). Utilice rand() para producir dos enteros positivos de un dígito. A continuación debería imprimir una pregunta coma la siguiente:

```
¿Cuánto es 6 veces 7?
```

A continuación el alumno escribe la respuesta. Su programa verifica la respuesta del alumno. Si es correcta imprime **"Muy bien!"** y a continuación solicita otra multiplicación. Si la respuesta es incorrecta imprimirá **"No. Por favor intenta nuevamente"** y a continuación permitirá que el alumno vuelva a intentar con la misma pregunta de forma repetida hasta que al final la conteste correctamente. El programa debe indicarle al alumno una forma de terminar la ejecución.

**P8**. La utilización de las computadoras en la educación se conoce como Instrucción Asistida por Computadora (CAI). Un problema que se desarrolla en los entornos CIA es la fatiga del alumno. Este problema puede ser enfrentado variando el diálogo de la computadora para retener la atención del alumno. Modifique el programa del ejercicio anterior de modo que este escoja de forma aleatoria uno de cuatro posibles mensajes tanto para respuestas correctas como para respuestas incorrectas. Los cuatro posibles mensajes en cada caso son:

**Respuestas correctas**:

```
Muy bien!
Excelente!
Buen trabajo!
Sigue haciéndolo bien!
```

**Respuestas incorrectas**:

```
No. Por favor trata de nuevo.
Incorrecto. Trata una vez más.
No te rindas!
No. Trata de nuevo
```

**Nota**: Mediante el generador de números aleatorios, seleccione un número entre 1 y 4 para desplegar un mensaje diferente para cada respuesta. Presente la respuesta mediante una estructura switch.

**P9**. Los sistemas más avanzados de CAI vigilan el rendimiento del alumno a lo largo de un periodo de tiempo. La decisión para empezar un tema nuevo se basa a menudo en el éxito del alumno en relación con temas anteriores. Modifique el programa del ejercicio anterior para contar el número de respuestas correctas e incorrectas del estudiante. Una vez el estudiante decida terminar la ejecución del programa, el programa debe calcular y mostrar el porcentaje de respuestas correctas respecto al total de preguntas que le hizo el programa. Si el porcentaje es menor a 75%, el programa deberá imprimir el mensaje **"Por favor pídele ayuda al instructor" y termina**.

