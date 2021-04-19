#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){
    int file_desc = open("tricky.txt", O_WRONLY|O_CREAT|O_APPEND, S_IRWXU);

    // here the newfd is the file descriptor of stdout (i.e. 1)
    dup2(file_desc, 1);

    // All the printf statements will be written in the file
    // "tricky.txt"
    printf("I will be printed in the file tricky.txt\n");

    return 0;
}