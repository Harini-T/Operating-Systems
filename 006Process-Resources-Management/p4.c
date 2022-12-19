/* 
Following program changes aore file size limit 0 to 10000 and receives SIGQUIT signal. You can check with ls command that core file is generated.
*/

#include<stdio.h>
#include<sys/resource.h>
int main(){
	struct rlimit v;
	
	getrlimit(RLIMIT_CORE, &v);
	printf("CPU Time: soft limit = %u, hard limit=%u\n",(int)v.rlim_cur, (int)v.rlim_max);
	
	v.rlim_cur=60;
	
	setrlimit(RLIMIT_CORE, &v);
	
	getrlimit(RLIMIT_CORE, &v);
	printf("CPU Time: soft limit = %u, hard limit=%u\n",(int)v.rlim_cur, (int)v.rlim_max);
	
	while(1);
	
}
