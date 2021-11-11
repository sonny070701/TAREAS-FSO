#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	
	char nombre1[64];
	char nombre2[64];
	int p;
	
	printf("Introduzca nombre de programa 1: \n");
	scanf("%s", nombre1);
	printf("Introduzca nombre de programa 2: \n");
	scanf("%s", nombre2);
	
	p = fork();
	if(p == 0){
		execlp(nombre1, nombre1, (char *)NULL);
		exit(1);
	}
	
	else{
		execlp(nombre2, nombre2, (char *)NULL);
	}
	wait(NULL);
}