#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int fib(int n);
int main(int argc, char *argv[]) {
	int n;
	do{
		printf("enter a number:");
		scanf("%d",&n);
	}while(n<1);
	int result=fib(n);
	printf("%d",result);
	return 0;
}
int fib(int n){
	if(n<=2)
	return 1;
	return fib(n-1)+fib(n-2);
}
