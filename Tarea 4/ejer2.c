#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
	
	int pid;
	int status;
	
	pid = fork();
	if (pid == 0) {
		printf("hola, soy el hijo: %d\n", getpid());
		sleep(1);
		exit(0);
	}
	else{
		sleep(1);
		printf("soy el padre: %d\n", getppid());
		sleep(19);
	}
	wait(&status);
	return 0;
}
		