//The following program implements " ls|wc-l " command

#include<stdio.h>
#include<unistd.h>
int main(){
	int p[2];
	pipe(p);
	if(fork()==0){
		//Child1 executes ls
		close(p[0]);
		close(1);
		dup(p[1]);
		execlp("ls","ls",(char *)NULL);
	}
	else{
		if(fork()==0){
			//child2 executes wc -l
			close(p[1]);
			dup2(p[0],0);
			execlp("wc","wc","-l",(char*)NULL);
		}
		else{
			//Parent closes unused descriptors
			close(p[0]);
			close(p[1]);
			wait(0);
			wait(0);
		}
	}
}
