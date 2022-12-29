#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
int main(){
	struct dirent *p;
	DIR *dp;
	dp=opendir(".");
	if(dp==0){
		perror("opendir");
		return;
	}
	while(p=readdir(dp))
		printf("%s ",p->d_name);
	printf("\n");
}
