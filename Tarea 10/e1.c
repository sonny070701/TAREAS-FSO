#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void P(){
	printf("A\n");
	printf("B\n");
	printf("C\n");
	exit(0);
}

void Q() {
	printf("E\n");
	printf("D\n");
	exit(0);
}


int main (){
	int p;
	p = fork();
	if (p==0)
		P();
	p = fork();
	if (p==0)
		Q();
}