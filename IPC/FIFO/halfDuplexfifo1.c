#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>


int main(){
	int fdr,fdw;
	char a[100], b[100];
	
	mkfifo("fifohd1",0600);
	perror("mkfifo");
	mkfifo("fifohd2",0600);
	perror("mkfifo");
	fdr=open("fifohd1",O_RDWR);
	fdw=open("fifohd2",O_RDWR);
	while(1){
		printf("You...\n");
		scanf("%[^\n]",a);
		write(fdw,a,strlen(a)+1);
		bzero(b,sizeof(b));
		read(fdr,b,sizeof(b));
		printf("\t\tFrom Hyderabad...\n\t\t%s\n\t\t******\n",b);
	}
}
