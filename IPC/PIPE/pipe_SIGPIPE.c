#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

void my_isr(int n){
printf("in ISR %d... %s\n",n,strsignal(n));
}

int main(){
int p[2],a=20;
pipe(p);
perror("pipe");
signal (SIGPIPE, my_isr);
close(p[0]);	//read end closed
write(p[1],&a,4);
perror("write");
}
