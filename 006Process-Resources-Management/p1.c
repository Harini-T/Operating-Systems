//Following program gets the resources soft and hard limits

#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>

int main(){
	struct rlimit v;
	
	getrlimit(RLIMIT_STACK,&v);
	printf("Stack: soft limit = %u, hard limit=%u\n",(int)v.rlim_cur, (int)v.rlim_max);
	
	getrlimit(RLIMIT_CPU, &v);
	printf("CPU Time: soft limit = %u, hard limit=%u\n",(int)v.rlim_cur, (int)v.rlim_max);
	
	getrlimit(RLIMIT_FSIZE, &v);
	printf("File size: soft limit = %u, hard limit=%u\n",(int)v.rlim_cur, (int)v.rlim_max);
	
	getrlimit(RLIMIT_NPROC, &v);
	printf("Number of processes: soft limit = %u, hard limit=%u\n",(int)v.rlim_cur, (int)v.rlim_max);

	getrlimit(RLIMIT_NOFILE, &v);
	printf("Number of files: soft limit = %u, hard limit=%u\n",(int)v.rlim_cur, (int)v.rlim_max);
}
