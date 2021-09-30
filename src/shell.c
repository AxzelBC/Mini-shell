#include "shell.h"

void promtShell(){
    /* Arreglos. */
    char hostname[PATH_MAX+1];
    char login[PATH_MAX+1];
    char directory[PATH_MAX+1];
    char flag[] = "/";

    /* Llenado de Arreglos. */
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

void pEComando(char* comando){
    
    /* Cadena. */
    char* cadena[MAX_COMANDO];

    /* Delimitador */
    const char delimitador[] = " ";

    /* Contadores. */
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

    commandBasic(i,cadena);
}


void pPComando(char* comandoPipe){
    /* Cadena */
    char p1Cadena[MAX_COMANDO];
    char p2Cadena[MAX_COMANDO];

    /* Delimitador */
    const char delimitador[] = "|";

    /* Inserción de comandos. */
    char *token = strtok(comandoPipe, delimitador);
    strcpy(p1Cadena,token);
    token = strtok(NULL, delimitador);
    strcpy(p2Cadena,token);

    commandPipe(p1Cadena,p2Cadena);
}


void leerComando(char* comando){
    int _pipe = 124, _salida = 62;

    /* Si hay pipe. */
    if (strchr(comando, _pipe)){
        pPComando(comando);
    // } else if (/* condition */){ //Si hay salida.
        /* code */
    /* Comando básico. */
    } else {
        pEComando(comando);
    }    
}


void commandBasic(int argc, char* argv[]){
    argv[argc] = NULL;

    execvp(argv[0], argv);

    fprintf(stderr,":( %s: no esta definido.\n", argv[1]);
    exit(EXIT_FAILURE);
}


/**
 * Recibir la cadena de punteros solamente.
 * usar el código de "2.pipes.c" para general el pipe usando el arreglo de pipe(fd).
 * usar el switch para despejar los casos.
 * en vez de usar el "execlp" se usará el "leerComando",
 * para cuando detecte otra caracteristica cómo | o > la tome en cuenta,
 * hasta llegar a un comando simple.
 */
void commandPipe(char* pComando, char* sComando){
    pid_t pid;
    int fd[2];

    if (pipe(fd) == -1) {
	    perror("Creating pipe");
	    exit(EXIT_FAILURE);
    }

    switch(pid = fork()) {

        case 0:
	        // The child process will execute wc.
	        // Close the pipe write descriptor.
	        close(fd[WRITE]);
	        // Redirect STDIN to read from the pipe.
	        dup2(fd[READ], STDIN_FILENO);
	        // Ejecuta segundo comando.
	        leerComando(sComando);

        case -1:
	        perror("fork() failed)");
    	    exit(EXIT_FAILURE);

        default:
	        // The parent process will execute ls.
	        // Close the pipe read descriptor.
	        close(fd[READ]);
	        // Redirect STDOUT to write to the pipe.
	        dup2(fd[WRITE], STDOUT_FILENO);
	        // Ejecuta primer comando.
	        leerComando(pComando);
    }
}

void commandOutfile(char* comando, char* salida){
    
}