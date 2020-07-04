#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

char *format_time(time_t time);

int main(int argc, char *argv[]) {
  struct stat stat_struct;
  char *file_type;

  for (int i = 1; i < argc; i++) {
    if(lstat(argv[i],&stat_struct) < 0){
      printf("Error al leer el archivo.\n\n");
      continue;
    }

    if (S_ISDIR(stat_struct.st_mode)) {
      file_type = "directorio";
    } else if (S_ISLNK(stat_struct.st_mode)) {
      file_type =  "link simbólico";
    } else {
      file_type = "-Archivo regular";
    }

    // Formatear la salida como la de stat() 
    printf("Archivo: %s\tTipo de archivo: %s\n", argv[i], file_type);
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
 
  return 0;
}

char *format_time(time_t time) {
  char *c_time_string;
  c_time_string = ctime(&time);
  return c_time_string;
}