#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

int chldpid;

void my_isr(int n){
	printf("In ISR...%d\n",n);
	if(n==SIGCHLD){
		printf("Child completes\n");
	}
	else if(n==SIGALRM){
		if(kill(chldpid,0)!=-1)	//check child process is still alive or not
		{
			printf("child terminated\n");
			signal(SIGCHLD,SIG_DFL);	//if terminated ignore sigchld signal
			kill(chldpid,9);
		}	

	}
}

int main(){
	if((chldpid=fork())==0){
		int d;
		srand(getpid());	//random delay generation
		d=rand()%10+1;
		printf("In Child...%d\n",d);
		sleep(d);
		printf("Out child...\n");
	}
	else{
		struct sigaction v;
		v.sa_handler = my_isr;
		sigemptyset(&v.sa_mask);
		v.sa_flags = SA_NOCLDSTOP | SA_NOCLDWAIT;
		sigaction(SIGCHLD,&v,0);
		v.sa_flags=0;
		sigaction(SIGALRM,&v,0);
		alarm(5);
		printf("Hello\n");
		sleep(10);
	}
}
