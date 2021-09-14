#include "headers/shell.h"

void readCommand(char *cadCommand[CHAR_MAX]){
    
    printf("Funciono\n");
    // int tam = sizeof(cadCommand) / sizeof(char *);

    // for (int i = 0; i < tam; i++){
    //     printf("%s\n", cadCommand[i]);
    // }
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