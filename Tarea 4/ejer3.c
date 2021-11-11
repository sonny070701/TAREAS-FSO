#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	if(fork() == 0) {
		sleep(20);
	}else{
		sleep(1);
	}
	
	wait(NULL);
	return 0;
}