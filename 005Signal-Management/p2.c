/*
When you press ^\ [ctrl C] for infinetly running program, the program terminates on reception of quit process signal (SIGQUIT). This is asynchronous signal
*/

#include<stdio.h>
int main(){
	printf("Hi...\n");
	while(1);
}
