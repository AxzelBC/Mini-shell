#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "headers/shell.h"

void leerCommand(char** cadCommand){
    
}

void commandBasic(int argc, char** argv){
    argv[argc] = NULL;

    execvp(argv[1], argc+1);

    fprintf(stderr,":( %s: no esta definido.\n", argv[1]);
    exit(EXIT_FAILURE);
}

void commandPipe(int argc1, char** argv1){

}

void commandOutfile(int argc2, char** argv2){

}