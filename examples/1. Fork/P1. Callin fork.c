#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){
  printf("Hola mundo, (Pid: %d)\n", (int)getpid());

  int rc = fork();
  if (rc < 0) {
    // fork failed
    fprintf(stderr, "Fork failed.\n");
    exit(1);
  }
  else if (rc == 0) {
    //Child (new process)
    printf("Hello, I am child (Pid:%d)\n",(int) getpid());
  }
  else {
    //Parent goes down this path (main)
    printf("Hello, I am parent of %d (Pid:%d)\n",rc, (int) getpid());
  }

  return 0;
}
