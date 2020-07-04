#include <stdio.h>
#include <time.h>

int count_rows(const char *ptr);

int main(int argc, char const *argv[]) {
  int n = count_rows(argv[1]);
  int nums[n];
  long long int suma = 0;
  FILE *myFile = fopen(argv[1], "r");;

  // Cargar datos en el vector
  for (int i = 0; i < n; i++) {
    fscanf(myFile, "%d", &nums[i]);
  }

  clock_t begin = clock();
  for (int i = 0; i < n; i++) {
    suma += nums[i];
  }
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Suma: %lld\n", suma);
  printf("Tiempo: %f", time_spent);
  return 0;
}

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