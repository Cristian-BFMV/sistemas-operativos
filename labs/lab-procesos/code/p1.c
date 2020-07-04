#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
    int x = 100;

    if (fork() > 0) {
        printf("Parent process: %d \n", x);
    } else  {
      printf("Child process: %d \n", x);
    }

    return 0;
}