/**
 * Ambos tienen acceso al descriptor del archivo.
 * También tienen permitido escribir sobre el archivo,
 * Creo que el orden de escritura depende de cómo se 
 * determine el orden de ejecución por parte del scheduler.
 * 
 * Parece que hay algunas inconsistencias en el resultado
 * debido a la concurrencia.
 **/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    int filedesc = open("jeje.txt", O_WRONLY);
    int rc = fork();

    if (rc == 0) {
        printf("%s%d", "child: ", filedesc);
        write(filedesc, "This was written by child\n", 27);
    } else {
        write(filedesc, "This was written by parent\n", 29);
    }

    write(filedesc, "This was written after the if", 28);
    return 0;
}
