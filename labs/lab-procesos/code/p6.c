#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){

    int process = fork();

    if (process == 0) {
        sleep(3);
        printf("Child finished sleeping\n");
    } else {
        waitpid(process, 0, 0);
        printf("Parent finished waiting\n");
    }
    
    return 0;
}