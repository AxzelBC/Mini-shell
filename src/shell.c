#include "shell.h"

void promtShell(){
    char hostname[PATH_MAX+1];
    char login[PATH_MAX+1];
    char directory[PATH_MAX+1];
    char flag[] = "/";

    gethostname(hostname, sizeof(hostname));
    getlogin_r(login, sizeof(login));
    getcwd(directory, sizeof(directory));

    char *dir = strtok(directory, flag);

    if(dir != NULL){
        while(dir != NULL){
            // printf("Token: %s\n", dir);
            strcpy(directory, dir);
            dir = strtok(NULL, flag);
        }
    }

    printf(ANSI_COLOR_GREEN "[%s@%s " ANSI_COLOR_RESET ,login,hostname);
    printf("%s]$ ",directory);
}

void readCommand(char* comando){
    
    char * cadena[128];
    const char delimitador[] = " ";
    char *token = strtok(comando, delimitador);
    int i = 0;

    if(token != NULL){
        do{
            // printf("Token2: %s\n", token);
            cadena[i] = token;
            // printf("Cadena[%d]: %s\n",i,cadena[i]);
            i++;
            token = strtok(NULL, delimitador);
        }while(token != NULL);
        cadena[i+1] = "\0";
    }

    commandBasic(i,cadena);
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