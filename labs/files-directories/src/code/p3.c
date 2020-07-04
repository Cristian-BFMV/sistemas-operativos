#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){
	FILE *file;
  char c;
  int lines_to_show;
  int counter;
  unsigned int position;

  if(argc != 3) {
    printf("[Error]: Número de argumentos inválido.\n");
    return 1;
  }

  lines_to_show = abs(atoi(argv[1])); // toma el parámetro del número de líneas y lo convierte a entero positivo
  if (lines_to_show == 0) {
    printf("[Error]: Número de líneas incorrecto.\n");
    return 1;
  }

  file = fopen(argv[2], "r");
  if(file == NULL) {
		printf("[Error]: Arhivo no encontrado.\n");
    return 1;
	}

  // Posicionarse sobre el final del archivo
  fseek(file, 0, SEEK_END);
  position = ftell(file);

  // Empezamos a buscar los finales de línea para poder pararnos sobre la línea de interpes
  counter = 0;
  while (counter < lines_to_show) {
    fseek(file, --position, SEEK_SET);
    c = fgetc(file);
    if (c == '\n' || c == EOF) {
      counter++;
    }
  }

  if ((int) position < 0) {
    printf("[Error]: Está intentando mostrar más líneas que las que contiene el archivo.\n");
    return 1;
  }

  // Después de posicionarse sobre la n-ésima línea, empezar a imprimir
  while (counter > 0 ) {
    fseek(file, position++, SEEK_SET);
    c = fgetc(file);
    printf("%c",c);
    if (c == '\n') {
      counter--;
    }
  }

  // Mostrar el último caracter, no se mostraba en el ciclo. Un bug al parecer
  fseek(file, -1, SEEK_END);
  c = fgetc(file);
  printf("%c",c);

  return 0;

}