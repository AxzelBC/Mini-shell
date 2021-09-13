/**
 * @file main.c
 * @author Alejandro C. Mosquera (AxzelBC)
 * @code 2022499
 * @brief Archivo principal de la shell.
 * @version 0.1
 * @date 2021-04-19
 */

/*
 *  Archivos de cabeceras (librerias).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <linux/limits.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include "src/headers/shell.h"

//Constantes
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(void){
    
    while (1){
        
        /**
         * @brief Promt del shell.
         */
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

        /**
         * @brief Almacena le comando ingresado.
         */
        char *comando[CHAR_MAX];
        printf(ANSI_COLOR_GREEN "[%s@%s " ANSI_COLOR_RESET ,login,hostname);
        printf("%s]$ ",directory);
        scanf(" %127[^\n]",**comando);

        /**
         * @brief si el comando es 'exit' para la shell.
         */
        if (!strcmp("exit",**comando)){
            printf("Se acabó.\n");
            break;
            exit(EXIT_SUCCESS);
        }

        /**
         * @brief Creación de subproceso para los comandos
         */
        pid_t pid;
        pid = fork();

        int id = getpid();

        if (!pid){ // New process (child)
            printf("Pasé. %d\n",id);
            readCommand(comando);
        }
        else if (pid > 0){ // Parent process (dad)
            wait(NULL);
            printf("No pase.\n");
        }
        else{ // Error in PID
            perror("Error en la creación de pid\n");
            exit(EXIT_FAILURE);
        }
    }
}
