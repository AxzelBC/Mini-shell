#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

int main(int argc, char** argv){
	int contador = 1;

	pid_t pid = fork();

	assert(pid != -1);

	if(!pid){
		contador+=5;
	}
	else{
		contador+=2;
	}
                printf("Contador:%d\n",contador);
		return 0;
}
