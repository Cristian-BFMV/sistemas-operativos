/**
 * Adapted from https://github.com/asnr/ostep/blob/master/virtualisation/5_process_api/4_exec.c
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static const char LS_PATH[] = "/bin/ls";

int call_execl() {
    int rc = execl(LS_PATH, "ls", ".", NULL);
    return rc;
}

int call_execle() {
    char *env[] = { "COLUMNS=5", NULL };
    int rc = execle(LS_PATH, "ls", ".", NULL, env);
    return rc;
}

int call_execlp() {
    int rc = execlp("ls", "ls", ".", NULL);
    return rc;
}

int call_execv() {
    char *args[] = { "ls", "-l", NULL };
    int rc = execv(LS_PATH, args);
    return rc;
}

int call_execvp() {
    char *args[] = { "ls", "-l", NULL };
    int rc = execvp("ls", args);
    return rc;
}

int call_execvpe() {
  char *args[] = { "ls", "-lah", NULL };
  char *env[] = { "COLUMNS=5", NULL };
  int rc = execvpe(LS_PATH, args, env);
  return rc;
}

int main(int argc, char const *argv[]) {
    int forkrc = fork();
    
    if (forkrc == 0) {
        int exec_rc;
        exec_rc = call_execl();
        // exec_rc = call_execle();
        // exec_rc = call_execlp();
        // exec_rc = call_execv();
        // exec_rc = call_execvp();
        // exec_rc = call_execvpe();
    } else {
        wait(0);
    }
    return 0;
}
