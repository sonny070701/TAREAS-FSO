#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(){

    int pid;
    printf("Mi pid es %d\n",getpid());

    pid = fork();
    
    while(pid == 0) {
        printf("hijo: %d\n", getpid());
        
            int padre = getppid();
            kill(padre, 9);
            printf("Padre asesinado: %d\n", padre);

            exit(0);
        } 
    return 0;
}
        
        