#include "shell.h"

void promtShell(){
    //Arreglos
    char hostname[PATH_MAX+1];
    char login[PATH_MAX+1];
    char directory[PATH_MAX+1];
    char flag[] = "/";

    //Llenado de Arreglos
    gethostname(hostname, sizeof(hostname));
    getlogin_r(login, sizeof(login));
    getcwd(directory, sizeof(directory));

    char *dir = strtok(directory, flag);

    if(dir != NULL){
        while(dir != NULL){
            strcpy(directory, dir);
            dir = strtok(NULL, flag);
        }
    }

    printf(ANSI_COLOR_GREEN "[%s@%s " ANSI_COLOR_RESET ,login,hostname);
    printf("%s]$ ",directory);
}

void partirComando(char* comando){
    
    //Cadena.
    char* cadena[128];

    //Delimitador & flags.
    const char delimitador[] = " ";

    //Contadores.
    int i = 0;

    char *token = strtok(comando, delimitador);

    if(token != NULL){
        do{
            cadena[i] = token;
            i++;
            token = strtok(NULL, delimitador);
        }while(token != NULL);
        cadena[i+1] = "\0";
    }

    commandBasic(cadena,i);
}

void leerComando(char* comando){
    const char* pipe_ = "|", salida_ = ">";

    if () //Si hay pipe.
    {
        /* code */
    } else if (/* condition */) //Si hay salida.
    {
        /* code */
    }
    
    
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