#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(){
	int fd;
	char a[15],ch;
	mkfifo("fifofile",0666);
	perror("mkfifo");
	fd=open("fifofile",O_WRONLY);
	perror("open");
	do{
		printf("Process 1\n");
		printf("Enter data\n");
		scanf("%s",a);
		write(fd,a,strlen(a)+1);
		perror("write");
	}
	while(1);
}
