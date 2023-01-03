/*
Following program handles SIGXFSZ signal, its disposition is changed to signal handler. The maximum file size limit is changed to 5characters and process tries to write more than 5 characters, resulting in reception of SIGXFSZ signal
*/

#include<stdio.h>
#include<sys/resource.h>
#include<string.h>
#include<signal.h>

void my_isr(int n){
	//strsignal() returns string describing signal
	printf("In ISR %d %s\n",n,strsignal(n));
}

int main(){
	FILE *fp;
	struct rlimit v;
	
	signal(SIGXFSZ, my_isr);
	
	getrlimit(RLIMIT_FSIZE, &v);
	printf("File size: soft limit = %u, hard limit=%u\n",(int)v.rlim_cur, (int)v.rlim_max);
	
	v.rlim_cur=5;
	setrlimit(RLIMIT_FSIZE,&v);
	
	getrlimit(RLIMIT_FSIZE, &v);
	printf("File size: soft limit = %u, hard limit=%u\n",(int)v.rlim_cur, (int)v.rlim_max);
	
	fp=fopen("DATA","w");
	fwrite("abcdefghijkl",12,1,fp);	
	
}
