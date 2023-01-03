#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
int main(){
	int fd1,fd2;
	char a[20];
	fd1=open("f1",O_RDWR);
	perror("open_1");
	
	fd2=open("f2",O_RDWR);
	perror("open_2");
	
	if(fork()==0){
		//child reading fifo2
		while(1){
			read(fd2,a,sizeof(a));
			printf("\t%s\n",a);
		}
	}
	else{
		//parent waiting fifo1
		while(1){
			scanf("%s",a);
			write(fd1,a,strlen(a)+1);
		}
	}
}
