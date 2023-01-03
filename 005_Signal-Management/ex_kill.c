/*
The following program demonstrates the use of kill(). This program takes two command line arguments, a signal number and a process IDs and uses kill() to send the signal to the specified process. If signal 0 is specified, then the program reports on the existence of the target process
*/

#include<stdio.h>
#include<stdarg.h>
#include<signal.h>
#include<sys/types.h>
#include<errno.h>

int main(int argc, char **argv){
	int r,sig;
	if(argc!=3){
		printf("Usage: /mykill pid signum\n");
		return;
	}
	sig = atoi(argv[2]);
	r = kill(atoi(argv[1]),sig);
	if(sig!=0){
		if(r==-1)
			perror("Kill");
	}
	else{
		if(r==0){
			printf("Process exists and we can sent it to a signal\n");
		}
		else{
			if(errno == EPERM)
				printf("Process exists, No permission to send signal\n");
			else if(errno == ESRCH)
				printf("Process doesnt exist\n");
			else
				perror("kill");
		}
	}
	return 0;
}
