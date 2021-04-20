/**
 * @file main.c
 * @author Alejandro C. Mosquera (AxzelBC)
 * @code 2022499
 * @brief Archivo principal de la shell.
 * @version 0.1
 * @date 2021-04-19
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define TAM_MAXIMO 128

int main(void){
    
    while (1)
    {
        /**
         * @brief Almacena le comando ingresado.
         */
        char comando[TAM_MAXIMO];
        printf("$ ");
        scanf(" %127[^\n]",comando);

        /**
         * @brief si el comando es 'exit' para la shell.
         */
        if (!strcmp("exit",comando))
        {
            printf("Se acabó.\n");
            break;
            exit(EXIT_SUCCESS);
        }

        /**
         * @brief Creación de subproceso para los comandos
         */
        pid_t pid;
        pid = fork();
        if (!pid) // New process (child)
        {
            /* code */
        }
        else if (pid > 0) // Parent process (dad)
        {
            wait(NULL);
        }
        else // Error in PID
        {
            perror("Error en la creación de pid\n");
            exit(EXIT_FAILURE);
        }
    }
}
