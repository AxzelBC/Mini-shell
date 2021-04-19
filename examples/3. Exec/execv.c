#include <unistd.h> // execvp()
#include <stdio.h>  // perror()
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

int main(void){
    char *const cmd[] = {"/usr/bin/ls", "-l", NULL};

    execv(cmd[0], cmd);

    perror("Return from execv() not expected");
    exit(EXIT_FAILURE);
}