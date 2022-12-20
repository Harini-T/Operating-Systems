#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void my_isr(int n){
	printf("In ISR...\n");
	wait(0);
}

int main(){
	if(fork()==0){
		printf("In Child...\n");
		sleep(10);
		printf("Out child...\n");
	}
	else{
		signal(SIGCHLD, my_isr);
		while(1);
	}
}
