#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	
	char nombre[64];

	do{
				
		printf("Introduzca nombre:  ");
		scanf("%s", nombre);
		system(nombre);
	}
	while(*nombre != *"exit");	
	return 0;
}


	