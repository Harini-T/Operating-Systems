#include<stdio.h>
#include<time.h>
int main(){
	time_t t1;
	while(1){
		t1=time(0);
		printf("%u\n",t1);
		sleep(1);
		system("clear");
	}
}
