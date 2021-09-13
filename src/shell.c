#include "headers/shell.h"

void readCommand(char *cadCommand[CHAR_MAX]){
    printf("Funciono\n");
    printf("%s",cadCommand[0]);
}

void commandBasic(int argc, char* argv[]){
    argv[argc] = NULL;

    execvp(argv[0], argv);

    fprintf(stderr,":( %s: no esta definido.\n", argv[1]);
    exit(EXIT_FAILURE);
}

void commandPipe(int argc1, char** argv1){

}

void commandOutfile(int argc2, char** argv2){
    
}