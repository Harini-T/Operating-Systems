#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char **argv){
	struct stat v;
	if(argc!=2){
		printf("Usage:./a.out filename\n");
		return;
	}
	
	if(stat(argv[1],&v)<0){
		perror("Stat");
		return;
	}
	printf("inode number = %d\nsize of file=%d\nnumber of b;ocks=%d\npermission=%o\n",v.st_size,v.st_blocks,v.st_mode);
}
