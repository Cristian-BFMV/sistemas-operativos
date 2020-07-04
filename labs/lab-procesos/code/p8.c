#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int pipe_fds[2];
  int piperc = pipe(pipe_fds);

  if (fork() == 0) {
    // First child: write to stdout
    dup2(pipe_fds[1], STDOUT_FILENO);
    printf("Jeje from child 1\n"); /* redirect standard output to pipe_A write end */
  } else {
    if (fork() == 0) {
      // Second child: reads from stdin
      dup2(pipe_fds[0], STDIN_FILENO);

      char msg[101];
      char endmsg;
      fgets(msg, 101, stdin);

      printf("Child 2 recieved: %s\n", msg);
    }
  }

  return 0;
}