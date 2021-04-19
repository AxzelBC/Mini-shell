/*
 * Aplicación de wait();
 *
 * Si es 0 (hijo), imprimir Fibonacci de 50
 * Sin wait
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>

long int fibonacci(long int num);

int main(int argc, char* argv[]){
  pid_t pid;
  long int resultado = 0;
  int fibo;

  pid = fork();

  assert(pid >= 0);

  if (argc == 2) {
    fibo = atoi(argv[1]);
  } else {
    fibo = 10;
  }

  if (pid == 0) {
    resultado = fibonacci(fibo);
  } else {
    wait(NULL);
    printf("Este es padre\n");
  }
  
  printf("Resultado: %ld\n",resultado);

  if (resultado > 0) {
    printf("Sisas, correcto.\n");
      return 0;
  } else {
    printf("Pelao, pongale lont int.\n");
    return 1;
  }
}


long int fibonacci(long int num)
{
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    else
        return fibonacci(num-1) + fibonacci(num-2);
}