/*
The following program disables the SIGINT signal for one occurence and if it arrives second time then default action is performed
*/

#include<stdio.h>
#include<signal.h>

void my_isr(int n){
	printf("In ISR...%d\n",n);
	signal(2,SIG_DFL);	//Signal disposition is restored to default for next occurence
}

int main(){
	signal(SIGINT,my_isr);	//Signal disposition is changed
	printf("%d\n",getpid());
	while(1);
}
