/* 
The following code tries to divide by zero resulting in the program termination by floating point exception signal (SIGFPE). This signal occured synchronously
*/

#include<stdio.h>
int main(){
	int a=5, b=0,c;
	c=a/b;
	printf("%d\n",c);
}
