#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int main(int argc, char **argv){
	int id,ret;
	if(argc!=2){
		printf("Usage:./get semnum\n");
		return;
	}
	id=semget(4,5,IPC_CREAT|0666);
	perror("semget");
	printf("semaphore id=%d\n",id);
	
	ret=semctl(id,atoi(argv[1]),GETVAL);
	perror("semctl");
	printf("semvalue ret=%d\n",ret);
}
