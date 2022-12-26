/* 
The following program implements communication between parent and child process. Parent process scans text from keyboard and sends to child process, which converts text form lowercase to uppercase and prints on screen
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int p[2],i;
	pipe(p);
	perror("pipe");
	if(fork()==0){
		//child prints on monitor
		char b[15];
		close(p[1]);
		while(1){
		read(p[0],b,sizeof(b));
		for(i=0;b[i];i++){
			if(b[i]>='a' && b[i]<='z')
			b[i]=b[i]-32;
		}
		printf("Data=%s\n",b);
		}
	}
	else{
		//parent sca from keyboard
		char a[15],ch;
		close(p[0]);
		while(1){
			printf("Enter data\n");
			scanf("%s",a);
			write(p[1],a,strlen(a)+1);
		}
	}
}	
