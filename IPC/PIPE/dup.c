#include<stdio.h>
int main(){
	int fd;
	fd=dup(1);
	printf("fd=%d\n",fd);
	write(fd,"hello",5);
}
