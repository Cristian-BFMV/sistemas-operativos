#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h> 
#include <stdbool.h>

char *format_time(time_t time);
void print_data(char *file);
void list_files(char *dir_path, bool details);

int main(int argc, char *argv[]) {
  if (argc == 1) {
    list_files(".", false);
  }

  if (argc == 2) {
    if (strcmp(argv[1],"-l") == 0) {
      list_files(".", true);
    } else {
      list_files(argv[1], false);
    }
  }

  if (argc == 3) {
    if (strcmp(argv[1],"-l") == 0) {
      list_files(argv[2], true);
    } else {
      printf("[Error]: El parámetro -l debe ser el primero.");
    }
  }

  if (argc > 3) {
    printf("[Error]: Uso incorrecto\n\t\t./ejecutable [-l] [directorio]");
  } 
 
  return 0;
}

void list_files(char *dir_path, bool details) {
  DIR *d;
  struct dirent *dir;
  char file_path[2048];

  d = opendir(dir_path);
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      snprintf(file_path, sizeof file_path, "%s/%s", dir_path, dir->d_name);
      printf("%s\n", file_path);
      if (details) {
        print_data(file_path);
      }
    }
    closedir(d);
  }
  return(0);

}

char *format_time(time_t time) {
  char *c_time_string;
  c_time_string = ctime(&time);
  return c_time_string;
}

void print_data(char *file) {
  struct stat stat_struct;
  char *file_type;

  if(lstat(file, &stat_struct) < 0){
    printf("Error al leer el archivo.\n\n");
    return;
  }

  if (S_ISDIR(stat_struct.st_mode)) {
    file_type = "directorio";
  } else if (S_ISLNK(stat_struct.st_mode)) {
    file_type =  "link simbólico";
  } else {
    file_type = "-Archivo regular";
  }

  // Formatear la salida como la de stat() 
  printf("Archivo: %s\tTipo de archivo: %s\n", file, file_type);
  printf("Tamaño: %d bytes \t Bloques: %d\n", stat_struct.st_size, stat_struct.st_blocks);
  printf("Tamaño bloque: %d\n",stat_struct.st_blksize);
  printf("Links: %d\n",stat_struct.st_nlink);
  printf("Último acceso: \t %s", format_time(stat_struct.st_atime));
  printf("Usuario (ID): %d \t Grupo (ID): %d\n", stat_struct.st_uid, stat_struct.st_gid);
  printf("Última modificación: \t%s", format_time(stat_struct.st_atime));

  printf("Permisos:");
  printf("%c", *file_type);
  printf( (stat_struct.st_mode & S_IRUSR) ? "r" : "-");
  printf( (stat_struct.st_mode & S_IWUSR) ? "w" : "-");
  printf( (stat_struct.st_mode & S_IXUSR) ? "x" : "-");
  printf( (stat_struct.st_mode & S_IRGRP) ? "r" : "-");
  printf( (stat_struct.st_mode & S_IWGRP) ? "w" : "-");
  printf( (stat_struct.st_mode & S_IXGRP) ? "x" : "-");
  printf( (stat_struct.st_mode & S_IROTH) ? "r" : "-");
  printf( (stat_struct.st_mode & S_IWOTH) ? "w" : "-");
  printf( (stat_struct.st_mode & S_IXOTH) ? "x" : "-");
  printf("\n\n");
 }