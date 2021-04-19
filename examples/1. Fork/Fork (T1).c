/**
 * @file Fork (T1).c
 * @author Alejandro Mosquera
 * @brief  Resolución del ejercicio de llamada dork de Api de procesos.
 * @version 0.1
 * @date 2021-04-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){
    int contador = 1;
    int hijo = fork();

    if(hijo == 0){
        contador += 5;
        printf("Contador:%d.\n", contador);
    }
    else{
        contador += 2;
        printf("Contador:%d.\n", contador);
    }

    return 0;
}