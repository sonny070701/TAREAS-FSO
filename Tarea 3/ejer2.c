#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {

	int i;
	int n;
	printf(" entrada n: ");
	scanf("%d", &n);
	n++;
		for(i=0;i<n;i++){

			printf("%d\n",i);
			
			fork();
		}
	return 0;
}