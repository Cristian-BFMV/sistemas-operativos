#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  if (fork() == 0) {
    printf("Print from child before closing STDOUT.\n");
    close(STDOUT_FILENO);
    printf("Print from child after closing STDOUT.\n");
  } else {
    printf("Print from parent.\n");
  }
  return 0;
}