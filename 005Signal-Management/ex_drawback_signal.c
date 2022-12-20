#include<stdio.h>
#include<signal.h>

void my_isr(int n){
	printf("\nIn ISR...%d\n",n);
	sleep(10);
	printf("\nOut...%d\n",n);
}

int main(){
	signal(SIGINT, my_isr);
	signal(SIGQUIT, my_isr);
	while(1);
}
