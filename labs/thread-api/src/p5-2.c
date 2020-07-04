#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <stdint.h>

int count_rows(const char *ptr);
void *sumar (void *arg);

typedef struct { 
  int *arr;
  int inicio;
  int fin;
} myarg_t;

int main(int argc, char const *argv[]) {
  int n = count_rows(argv[1]);
  int nums[n];
  int suma = 0;
  void *r1, *r2;
  FILE *myFile = fopen(argv[1], "r");
  pthread_t thread1, thread2;

  // Cargar datos en el vector
  for (int i = 0; i < n; i++) {
    fscanf(myFile, "%d", &nums[i]);
  }

  // Crear estructuras para pasar los argumentos
  myarg_t args1 = { nums, 0, (int)n/2 + 1 };
  myarg_t args2 = { nums, (int)n/2 + 1, n };

  // Crear hilos
  pthread_create(&thread1, NULL, sumar, &args1);
  pthread_create(&thread2, NULL, sumar, &args2);

  // Empezar a contar y esperar a que finalicen los hilos
  clock_t begin = clock();
  pthread_join(thread1, &r1);
  pthread_join(thread2, &r2);

  // Sumar el resultado de ambos hilos
  suma = (int)r1 + (int)r2;
  clock_t end = clock();

  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Suma: %d\n", suma);
  printf("Tiempo: %f", time_spent);
  return 0;
}

void *sumar (void *arg) {
  myarg_t *args = (myarg_t *) arg;

  int *arreglo = args->arr;
  int inicio = args->inicio;
  int fin = args->fin;
  int suma = 0;

  for (int i = inicio; i < fin; i++) {
    suma += arreglo[i];
  }

  return (void *) suma;
}

/**
 * Cuenta la cantidad de líneas del archivo
 **/
int count_rows(const char *filename) {
  FILE *my_file;
  my_file = fopen("numbers", "r");
  int count = 0;
  char chr;

  while ((chr = fgetc(my_file)) != EOF){
    if (chr == '\n') {
      count++;
    }
  }
  fclose(my_file);
  return count; 
}