/*
The following program handles the SIGALRM signal to generate alarms at 4seconds, 6seconds and 10 seconds and terminates the process at 12th second
*/

#include<stdio.h>
#include<stdarg.h>
#include<signal.h>

int i=0;
void my_isr(int sig){
	i++;
	if(i==1){
		printf("Alarm at 4second...\n");
		alarm(2);
	}
	else if(i==2){
		printf("Alarm at 6 second...\n");
		alarm(4);
	}
	else if(i>2){
		printf("Alarm at 10 second...\n");
		signal(SIGALRM,SIG_DFL);
		alarm(2);
	}
}

int main(int argc, char **argv){
	signal(SIGALRM, my_isr);
	alarm(4);
	while(1);
}
