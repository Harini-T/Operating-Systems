#include<stdio.h>
#include<signal.h>

void my_isr(int n){
	printf("In ISR...%d\n",n);
	printf("Out ISR...\n");
}

int main(){
	if(fork()==0){
		printf("In child...%d\n",getpid());
		while(1);
	}
	else{
		struct sigaction v;
		v.sa_handler=my_isr;
		//SIGCHLD disturbs parent on child suspend, resume,terminate
		//v.sa_flags=0;
		//sigchld will not disturb parent for suspend and resume
		//v.sa_flags=SA_NOCLDSTOP;
		//no need to write wait in ISR to remove vhild from zombie
		v.sa_flags=SA_NOCLDSTOP | SA_NOCLDWAIT;
		sigemptyset(&v.sa_mask);
		sigaction(17,&v,0);
		while(1);
	}
}

