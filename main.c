/**
 * @file main.c
 * @author Alejandro C. Mosquera (AxzelBC)
 * @code 2022499
 * @brief Archivo principal de la shell.
 * @version 0.1
 * @date 2021-10-01
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
    /* Variable de status para el hijo. */
    int status;
    do{
        /**
         * @brief Almacena le comando ingresado.
         */ 
        char comando[MAX_COMANDO];
        promtShell();
        scanf(" %255[^\n]",comando);


        /**
         * @brief si el comando es 'exit' para la shell.
         */
        if (!strcmp("exit",comando)){
            printf("Hasta pronto. :D\n");
            break;
            exit(EXIT_SUCCESS);
        }


        /**
         * @brief Creación de subproceso para los comandos, y verificación del PID.
         */
        pid_t pid = fork();
        assert(pid >= 0);

        /* Creación del proceso hijo. */
        if (!pid){
            leerComando(comando);
        }
        /* Verificación de estado del proceso padre .*/
        else if (pid > 0){
            wait(&status);
            /* Se verifica que el estado es de salida. */
            if (WIFEXITED(status)){
                if (!(WEXITSTATUS(status))){
                    /* Revisión del clear (estético) */
                    if(!strcmp("clear",comando)){
                        printf("");
                    } else{
                        printf("\n:)\n");
                    }
                } else{
                    printf("\n:(\n");
                }
            } else{
                return 1;
            }
        /* Error en PID */
        } else{
            perror("Error en la creación de pid\n");
            exit(EXIT_FAILURE);
        }
    } while (1);
}
