#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>

long int fibonacci(long int num);

int main(int argc, char** argv){
  pid_t pid;
  long int resultado = 0;
  long int* copia = &resultado;
  int fibo;

  pid = fork();

  assert(pid >= 0);

  if(argc == 2){
      fibo = atoi(argv[1]);
  }
  else{
      fibo = 10;
  }

  if (pid == 0)
  {
      *copia = fibonacci(fibo);

      printf("Soy hijo. Fibonacci de %d es :%ld \n", fibo, resultado);
      return 0;
  }
  else if (pid > 0)
  {
      int status = wait(&status);
      
      if((int)WIFEXITED(status) == 0){
          printf("Es de salida\n");

          printf("Valor de salidad de hijo: %d.\n",(int) WEXITSTATUS(status));
      }

      printf("Soy padre. Fibonacci de %d es :%ld \n", fibo, *copia);
      return 0;
  }
  else
  {
      fprintf(stderr, "Papi, la cagó");
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