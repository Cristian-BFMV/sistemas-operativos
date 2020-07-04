#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
    if (fork() == 0) {
      printf("From child: %d \n", wait(0));
    } else {     
      // printf("From parent: %d \n", wait(0));
    }
    return 0;
}