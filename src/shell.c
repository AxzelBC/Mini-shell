/**
 * @file shell.c
 * @author Alejandro C. Mosquera (AxzelBC)
 * @code 2022499
 * @brief Implementaciín de las funciones de shell.h.
 * @details La lógica de un ingreso de comando basado en las reglas | y >
 *          se puede asumir que existen 3 tipos de comandos:
 *          Básico: ls -l
 *          Basado en resultado (Pipe): ls -l | grep *.c
 *          Enviar resultado a un archivo: ls -l | grep *.c > archivo.txt
 * @version 0.1
 * @date 2021-10-01
 */

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

void pOComando(char* comandoOut) {
	/* Cadena */
    char p1Cadena[MAX_COMANDO];
    char p2Cadena[MAX_COMANDO];

    /* Delimitador */
    const char delimitador[] = ">";

    /* Insercion de comandos. */
    char *token = strtok(comandoOut, delimitador);
    strcpy(p1Cadena,token);
    token = strtok(NULL, delimitador);
    strcpy(p2Cadena,token);

    commandOutFile(p1Cadena, p2Cadena);
}

void leerComando(char* comando){
    int _pipe = 124, _salida = 62;

    /* Si hay pipe. */
    if (strchr(comando, _pipe)) {
        pPComando(comando);
    } else if (strchr(comando, _salida)) { //Si hay salida.
        pOComando(comando);
	} else {  /* Comando basico. */
        pEComando(comando);
    }    
}


void commandBasic(int argc, char* argv[]){
    argv[argc] = NULL;

    execvp(argv[0], argv);

    fprintf(stderr,":( %s: no esta definido.\n", argv[1]);
    exit(EXIT_FAILURE);
}


void commandPipe(char* pComando, char* sComando){
    pid_t pid;
    int fd[2];

    if (pipe(fd) == -1) {
	    perror("Creating pipe");
	    exit(EXIT_FAILURE);
    }

    switch(pid = fork()) {

        case 0:
	        // El proceso hijo se ejecuta con sComando.
	        // Cierra la escritura del descriptor del pipe.
	        close(fd[WRITE]);
	        // Redirect STDIN to read from the pipe.
	        dup2(fd[READ], STDIN_FILENO);
	        // Ejecuta segundo comando.
	        leerComando(sComando);

        case -1:
	        perror("fork() failed)");
    	    exit(EXIT_FAILURE);

        default:
	        // El proceso padre se manda a pComando.
	        // Se cierra el pipe que lee el descriptor.
	        close(fd[READ]);
	        // Redirecciona STDOUT a la escritura del pipe.
	        dup2(fd[WRITE], STDOUT_FILENO);
	        // Ejecuta primer comando.
	        leerComando(pComando);
    }
}

void commandOutFile(char* comando, char* salida){

    char cadena[MAXSTR];
	int s;
	int file; /* descriptor del archivo que se va a usar. */
	
	bzero(cadena, sizeof(char)*MAXSTR);
	remove_spaces(salida);
	file = open(salida, O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
	
	assert(file != -1);

	dup2(file, STDOUT_FILENO);
	pEComando(comando);
	close(file);
}


void remove_spaces(char* str) {
    char *write = str, *read = str;
	
	do {
	   if (*read != ' ')
    	   *write++ = *read;
	} while (*read++);
}
