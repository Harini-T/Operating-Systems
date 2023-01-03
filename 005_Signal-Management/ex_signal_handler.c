/*
Following program establishes the same handler for SIGINT and SIGQUIT. The code of the handler distinguishes the two sginals by examining the sig argument, and takes different actions for each signal.
*/

#include<stdio.h>
#include<signal.h>
int c;
void my_isr(int sig){
	printf("\nIn ISR...%d\n",sig);
	if(sig==2){
		printf("%d: SIGINT signal is delivered\n",sig);
		printf("square of %d is%d\n",c,c*c);
	}
	else if(sig==3){
		printf("%d : SIGQUIT signal is delivered\n",sig);
		printf("cube of %d is %d\n",c,c*c*c);
	}
}

int main(){
	signal(SIGINT,my_isr);
	signal(SIGQUIT,my_isr);
	printf("PID:%d\n",getpid());
	printf("Enter number\n");
	scanf("%d",&c);
	pause();
	pause();
}
