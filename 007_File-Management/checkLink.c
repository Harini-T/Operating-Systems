#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc, char **argv){
	struct stat v,v1;
	if(argc!=3){
		printf("Usage:./a.out file1 file2\n");
		return;
	}
	if(stat(argv[1],&v)<0){
		perror("stat");
		return;
	}
	if(stat(argv[2],&v)<0){
		perror("stat");
		return;
	}
	if(v.st_ino==v1.st_ino){
		lstat(argv[1],&v);
		lstat(argv[2],&v1);
		if(v.st_ino==v1.st_ino)
			printf("HardLink\n");
		else
			printf("SoftLink\n");
	}
	else
		printf("No Link\n");
}
