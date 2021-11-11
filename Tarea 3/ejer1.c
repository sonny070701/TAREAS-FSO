#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

	int p;
	int i;
	
	p=fork();

	if(p==0){

		for(i=0;i<10;i++){ 
			sleep(2);
			printf("Soy el hijo \n");
			
		}
		exit(0);	
	}
	else{
		for(i=0;i<10;i++){ 
			sleep(1);
			printf("Soy el padre \n");
			sleep(1);
		}
	}
	wait(NULL);	
	printf("Mi proceso hijo ha terminado");
	return 0;
}