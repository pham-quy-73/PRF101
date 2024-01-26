#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int isFib(int n);
int main(int argc, char *argv[]) {
	int n;
	do{
		printf("enter a possitive interger:");
		scanf("%d",&n);
	}while(n<1);
	if(isFib(n)==1){
		printf("It is a Fib element");
	}
	else{
		printf("It is not a Fib element");
	}
	return 0;
}
int isFib(int n){
	int t1=1, t2=1, f=1;
	if(n==1) return 1;
	while(f<n){
		f=t1+t2;
		t1=t2;
		t2=f;
	}
	return n==f;
}

