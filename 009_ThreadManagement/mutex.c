#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void* doSomething(void *arg){
	pthread_mutex_lock(&lock);
	printf("%s\n",arg);
	counter+=1;
	printf("\nJob %d started\n",counter);
	sleep(5);
	printf("\nJob %d finished\n",counter);
	
	pthread_mutex_unlock(&lock);
}

int main(){
	int i=0,err;
	printf("in main...%d\n",counter);
	pthread_mutex_init(&lock, NULL);
	
	pthread_create(&(tid[0]), NULL, doSomething, (void*)"Thread1");
	pthread_create(&(tid[1]), NULL, doSomething, (void*)"Thread2");
	
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&lock);
	printf("In main...%d\n",counter);
}
