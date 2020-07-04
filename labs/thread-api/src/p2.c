#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

void *factorial (void *args);

int main (int argc, char *argv[]) {
  pthread_t threads[argc];
  void* returns[argc];

  for (int i = 1; i < argc; i++) {
    pthread_create(&threads[i], NULL, factorial, argv[i]);
  }

  srand(time(0)); 
  for (int i = 1; i < argc; i++) {
    pthread_join(threads[i], &returns[i]);
    printf ("[Hilo %d] El factorial de %s es %lld\n", i, argv[i], (long long int)returns[i]);
  }
  return 0;
}

void *factorial (void *arg) {
  int n = atoi(arg) ;
  long long int resultado= 1;
  int num;

  for (num = 2; num <= n; num++) {
    resultado = resultado*num;
    printf ("Factorial de %d, resultado parcial %lld\n", n, resultado);
    sleep (random()%3);
  }

  return (void *) resultado;
}