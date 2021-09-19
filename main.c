/**
 * @file main.c
 * @author Alejandro C. Mosquera (AxzelBC)
 * @code 2022499
 * @brief Archivo principal de la shell.
 * @version 0.1
 * @date 2021-04-19
 */

/*
 *  Archivos de cabeceras (includes).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "src/shell.h"


int main(void){
    do{
        /**
         * @brief Almacena le comando ingresado.
         */ 
        char palabra[] = "ls -lAh";
        char comando[128];
        promtShell();
        scanf(" %127[^\n]",comando);


        /**
         * @brief si el comando es 'exit' para la shell.
         */
        if (!strcmp("exit",comando)){
            printf("Se acabó.\n");
            break;
            exit(EXIT_SUCCESS);
        }

        /**
         * @brief Creación de subproceso para los comandos
         */
        pid_t pid = fork();

        int id = getpid();

        if (!pid){ // New process (child)
            int status;
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
    } while (1);
}