#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  if (fork() == 0) { 
    // Child prints Hello
    printf("Hello \n");
  } else {
    // Parent prints Goodbye
    sleep(1);
    printf("goodbye \n");    
  }
  return 0;
}