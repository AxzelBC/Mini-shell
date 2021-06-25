/**
 * @file shell.h
 * @author Alejandro C. Mosquera (AxzelBC)
 * @code 2022499
 * @brief Declaración de funciones de la shell.
 * @details La lógica de un ingreso de comando basado en las reglas | y >
 *          se puede asumir que existen 3 tipos de comandos:
 *          Básico: ls -l
 *          Basado en resultado (Pipe): ls -l | grep *.c
 *          Enviar resultado a un archivo: ls -l | grep *.c > archivo.txt
 * @version 0.1
 * @date 2021-04-19 
 */


/**
 * @brief lee el comando ingresado y determina que tipo de comando es
 *        basandose en las tres caracteristicas definidas.
 * 
 * @param {string} cadCommand arreglo de caracteres (comando).
 */
void leerCommand(char** cadCommand);


/**
 * @brief ejecución de un comando básico.
 * 
 * @param {int} argc 
 * @param {string} argv 
 */
void commandBasic(int argc, char** argv);


/**
 * @brief Ejecución de un comando con Pipe (|).
 * 
 * @param {int} argc1
 * @param {string} argv1 
 */
void commandPipe(int argc1, char** argv1);


/**
 * @brief Ejecución de un comando con salida a un archivo (>).
 * 
 * @param {int} argc2 
 * @param {string} argv2 
 */
void commandOutfile(int argc2, char** argv2);