#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <assert.h>

long int Fibonacci(long int num);

int main(int argc, char** argv){
  int fibo;
  long int resultado;

  pid_t pid = fork();

  assert(pid >= 0);

  if(argc!=2){
    fibo = 50;
  }
  else{
    fibo = atoi(argv[1]);
  }

  if (!pid) {
    resultado = Fibonacci(fibo);
    printf("El fibonacci es:%ld.\n",resultado);
  }
  else {
    printf("Este es padre.\n");
  }

  return 0;
}

long int Fibonacci(long int num){
  if (num == 0) {
    return 0;
  }
  else if (num == 1) {
    return 1; 
  }
  else {
    return Fibonacci(num-2)+Fibonacci(num-1);
  }
}
