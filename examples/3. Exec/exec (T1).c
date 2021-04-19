#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv){
  argv[argc] = NULL;
  execvp(argv[1], argv+1);

  perror("Hay un error en el execvp\n");
  exit(EXIT_FAILURE);
}
