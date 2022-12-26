#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>


int main(){
	int fdr,fdw;
	char a[100], b[100];
	fdr=open("fifohd1",O_RDWR);
	fdw=open("fifohd2",O_RDWR);
	while(1){
		
		bzero(b,sizeof(b));
		read(fdr,b,sizeof(b));
		printf("\t\tFrom Bangalore...\n\t\t%s\n\t\t******\n",b);
		printf("You...\n");
		scanf("%[^\n]",a);
		write(fdw,a,strlen(a)+1);
	}
}
