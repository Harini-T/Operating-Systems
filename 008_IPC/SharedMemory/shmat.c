#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(int argc, char **argv){
	int id;
	char *p;
	id=shmget(atoi(argv[1]),atoi(argv[2]),IPC_CREAT|0666);
	perror("shmget");
	
	p=shmat(id,0,0);
	perror("shmat");
	printf("P=%u\n",p);
	printf("Enter data\n");
	scanf("%s",p);
	shmdt(p);
	perror("shmdt");
}
