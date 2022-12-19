#include<stdio.h>
#include<signal.h>
int main(){
	printf("Hello...%d\n",getpid());
	sleep(10);
	raise(SIGSEGV);
}
