#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv){
    printf("Hello world (pid:%d)·\n", (int) getpid());
    int hijo = fork();

    if (hijo < 0)//Fork failed; exit
    {
        fprintf(stderr,"For failed.\n");
        exit(1);
    }
    else if (hijo == 0) // Child (new process)
    {
        printf("Hello, I am child (pid:%d).\n", (int) getpid());
    }
    else //Parent goes down this path (main)
    {
        int hijo_wait = wait(NULL);
        printf("Hello, I am parent of %d (hijo_wait:%d) (pid:%d).\n",
                hijo, hijo_wait,(int)getpid());
    }
    
    return 0;
}