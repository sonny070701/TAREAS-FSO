#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
    long mtype;       /* message type, must be > 0 */
    char mtext[30];    /* message data */
};

void initsem(int buzon, int n) {

	n = 10;
	int i;
	buzon = msgget(0x1234, 0666|IPC_CREAT);
	if(buzon == -1) {

		fprintf(stderr,"No se pudo crear el buzón\n");
		exit(1);
	}

	for(i=0;i<10;i++) {
		n--;
		mensaje.mtype=1;	
		sprintf(mensaje.mtext,"Este es el mensaje %d",i);
		
		msgsnd(buzon,&mensaje,sizeof(struct msgbuf),IPC_NOWAIT);	// No espera a que sea recibido
		sleep(1);
		
	}
	exit(0);	
}

void waitsem(int buzon) {
	
	struct msgbuf mensaje;
	do {
		
		msgrcv(buzon,&mensaje,sizeof(struct msgbuf),1,0);
		printf("%s\n",mensaje.num);	
	} while(buzon != 0);  
	
	msgclt(buzon, IPC_RMID, NULL);
		
}

void signalsem(int buzon) {
	
	if(buzon != 0) {
		printf("buzon con mensaje");
	}
	else
		exit(0);
}
	
	
	