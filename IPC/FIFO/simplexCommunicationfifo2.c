#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(){
	int fd;
	char b[15];
	
	fd=open("fifofile",O_RDONLY);
	perror("open");
	printf("process 2\n");
	while(1){
		read(fd,b,sizeof(b));
		printf("%s\n",b);
	}
}
