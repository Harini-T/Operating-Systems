#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	struct flock v;
	char a[] = "ABCDEFGHIJKLMNOPQR";
	int i,fd;
	
	fd=open("data",O_RDWR | O_CREAT |O_APPEND,0666);
	
	v.l_type=F_WRLCK;
	v.l_whence=SEEK_SET;
	v.l_start=0;
	v.l_len=0;
	
	printf("Before\n");
	fcntl(fd,F_SETLKW,&v);
	printf("After\n");
	
	for(i=0;a[i];i++){
		write(fd,&a[i],1);
		sleep(1);
	}
	v.l_type=F_UNLCK;
	fcntl(fd,F_SETLKW,&v);
	printf("Done\n");

}
