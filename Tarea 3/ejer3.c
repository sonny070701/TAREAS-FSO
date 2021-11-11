#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
	int i;
	int n;
	int p=3;
	int status;
 	printf(" entrada n: ");
	scanf("%d", &n);
		for(i=0;i<n;i++){ 
			p=fork();
		
			if(p==0){
				printf("Proceso Hijo %d\n",i+1);
				exit(i+1);
			}
		}
	wait(&n);
	printf("FIN");
	return 0;
}