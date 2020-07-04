#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

void *factorial (void *args);

int main (int argc, char *argv[]) {
  pthread_t thread1, thread2;
  void *r1, *r2;

  pthread_create(&thread1, NULL, factorial, argv[1]);
  pthread_create(&thread2, NULL, factorial, argv[2]);

  srand(time(0)); 
  if (argc== 3) {
    pthread_join(thread1, &r1);
    pthread_join(thread2, &r2);
    printf ("El factorial de %s es %lld\n", argv[1], (long long int)r1);
    printf ("El factorial de %s es %lld\n", argv[2], (long long int)r2);
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