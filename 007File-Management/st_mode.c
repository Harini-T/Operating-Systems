#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char **argv){
	struct stat v;
	int mode;
	if(argc!=2){
		printf("Usage:./a.out fname\n");
		return;
	}
	
	if(lstat(argv[1],&v)<0){
		perror("stat");
		return;
	}
	printf("mode %o\n",v.st_mode);
	if(S_ISREG(v.st_mode))
		printf("regular file\n");
	else if(S_ISDIR(v.st_mode))
		printf("directory file\n");
	else if(S_ISLNK(v.st_mode))
		printf("link file\n");
	else if(S_ISCHR(v.st_mode))
		printf("character special file\n");
	else if(S_ISBLK(v.st_mode))
		printf("block special file\n");
	else if(S_ISFIFO(v.st_mode))
		printf("pipe file\n");
	else if(S_ISSOCK(v.st_mode))
		printf("socket file\n");	
}
