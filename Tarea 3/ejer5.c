#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	int p=2;
	char nombre[64];
	Here:
	printf("Introduzca nombre:  ");
	scanf("%s", nombre);
	p=fork();
	if(*nombre != *"exit"&&p==0){
		execlp(nombre, nombre, (char *)NULL);
	}
	wait(NULL);
	if(*nombre != *"exit"){
	goto Here;
}
	return(0);
}