#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<unistd.h>


struct msgbuf{
	long mtype;
	char data[20];
};

int main(){
	int id;
	struct msgbuf v;
	id = msgget(2,IPC_CREAT|0666);
	if(fork()==0){
		while(1){
			msgrcv(id,&v,sizeof(v.data),3,0);
			printf("\t%s\n",v.data);
		}
	}
	else{
		while(1){
			scanf("%s",v.data);
			v.mtype=2;
			msgsnd(id,&v,strlen(v.data)+1,0);
		}
	}
}
